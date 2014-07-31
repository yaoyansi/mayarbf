//////////////////////////////////////////////////////////////////////////
//
// Test program for the class RBFInterpolator
// 
// 2009 Karsten Noe
//
// Read the blog at cg.alexandra.dk for more information
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <GL/glew.h>												// Header File For The OpenGL32 Library
#include <gl\glut.h>												// Header File for Glut
#include "math.h"													// math functions
#include "RBFWapper.h"

#pragma comment( lib, "opengl32.lib" )								// Search For openhl32.lib while linking
#pragma comment( lib, "glu32.lib" )									// Search For glu32.lib while linking
#pragma comment( lib, "glut32.lib" )								// Search For glut32.lib while linking
#pragma comment( lib, "glew32.lib" )								// Search For glew32.lib while linking

//#include "ArcBall.h"												// ArcBall for navigation


#define M_PI 3.1415926535f
//#define _Render_Control_Point_

using namespace std;

/* windows size and position constants */
int GL_WIN_WIDTH = 800;
int GL_WIN_HEIGHT = 800;
int GL_WIN_INITIAL_X = 0;
int GL_WIN_INITIAL_Y = 0;

GLUquadricObj *quadratic;											// Used for rendering control points
GLUquadric *myQuad;

Matrix4fT   Transform   = {  1.0f,  0.0f,  0.0f,  0.0f,				// Arcball navigation: Final Transform
                             0.0f,  1.0f,  0.0f,  0.0f,
                             0.0f,  0.0f,  1.0f,  0.0f,
                             0.0f,  0.0f,  0.0f,  1.0f };

Matrix3fT   LastRot     = {  1.0f,  0.0f,  0.0f,					// Arcball navigation: Last Rotation
                             0.0f,  1.0f,  0.0f,
                             0.0f,  0.0f,  1.0f };

Matrix3fT   ThisRot     = {  1.0f,  0.0f,  0.0f,					// Arcball navigation: This Rotation
                             0.0f,  1.0f,  0.0f,
                             0.0f,  0.0f,  1.0f };

ArcBallT    ArcBall(GL_WIN_WIDTH, GL_WIN_HEIGHT );				                // NEW: ArcBall Instance
Point2fT    MousePt;												// Arcball navigation: Current Mouse Point
bool        isClicked  = false;										// Arcball navigation: Clicking The Mouse?
bool        isRClicked = false;										// Arcball navigation: Clicking The Right Mouse Button?
bool        isDragging = false;					                    // Arcball navigation: Dragging The Mouse?

									// This mesh will be continuously deformed and rendered

const int numControlPoints = 11;
RenderTriangleMesh* meshRenderer;									// Used for rendering a TriangleMesh.

vector<Scalar> controlPointDisplacementX;							// Displacement of control points in the X-direction
vector<Scalar> controlPointDisplacementY;							// Displacement of control points in the Y-direction
vector<Scalar> controlPointDisplacementZ;							// Displacement of control points in the Z-direction
#ifdef _Render_Control_Point_
BoundingSphere boundingSphere;										// Bounding sphere to give information about the size of the object.
#endif

void InitializeGlew()
{

	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}

	if (!(GLEW_ARB_vertex_buffer_object
		&& GLEW_EXT_framebuffer_object))
	{
		cerr << "Extensions not supported" << endl;
		exit(1);

	}

}


void InitializeOpenGL()					// Any GL Init Code & User Initialization Goes Here
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,640/480,1,-100);
	glMatrixMode(GL_MODELVIEW);

	// Start Of User Initialization
    isClicked   = false;								            // NEW: Clicking The Mouse?
    isDragging  = false;							                // NEW: Dragging The Mouse?

	glClearDepth (1.0f);											// Depth Buffer Setup
	glDepthFunc (GL_LEQUAL);										// The Type Of Depth Testing (Less Or Equal)
	glEnable (GL_DEPTH_TEST);										// Enable Depth Testing
	glShadeModel (GL_SMOOTH);										

	quadratic=gluNewQuadric();										// Create A Pointer To The Quadric Object
	gluQuadricNormals(quadratic, GLU_SMOOTH);						// Create Smooth Normals
	gluQuadricTexture(quadratic, GL_TRUE);							// Create Texture Coords

	GLfloat color[] = {1,1,1,1};
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);

	GLfloat lightpos[] = {0,0,0};
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);					// set light position

	GLfloat lightcolor[] = {1,1,1,1};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightcolor);					// set light color					

	glEnable(GL_LIGHT0);											// Enable Default Light
	glEnable(GL_LIGHTING);											// Enable Lighting
	glEnable(GL_COLOR_MATERIAL);									// Enable Color Material


}

void glutResize (int w, int h)
{ 
	GL_WIN_WIDTH = w;
	GL_WIN_HEIGHT = h;
	ArcBall.setBounds(GL_WIN_WIDTH, GL_WIN_HEIGHT);
	glViewport (0, 0, GL_WIN_WIDTH, GL_WIN_HEIGHT);
}


void glutMouse(int button, int state, int x, int y)
{

	MousePt.s.X=x;
	MousePt.s.Y=y;

	if(state == GLUT_DOWN)
	{
		isClicked = true;
		switch(button)
		{
		case GLUT_LEFT_BUTTON:
			LastRot = ThisRot;										// Set Last Static Rotation To Last Dynamic One
			ArcBall.click(&MousePt);								// Update Start Vector And Prepare For Dragging
			break;

		case GLUT_RIGHT_BUTTON:										// If Right Mouse Clicked, Reset All Rotations
			Matrix3fSetIdentity(&LastRot);								
			Matrix3fSetIdentity(&ThisRot);								
			Matrix4fSetRotationFromMatrix3f(&Transform, &ThisRot);		
			break;
		}
	} 
	else if (state == GLUT_UP)
	{

	}

}

void glutMotion(int x, int y)									// Perform Motion Updates Here
{
	MousePt.s.X=x;
	MousePt.s.Y=y;

	Quat4fT     ThisQuat;

	ArcBall.drag(&MousePt, &ThisQuat);						// Update End Vector And Get Rotation As Quaternion
	Matrix3fSetRotationFromQuat4f(&ThisRot, &ThisQuat);		// Convert Quaternion Into Matrix3fT
	Matrix3fMulMatrix3f(&ThisRot, &LastRot);				// Accumulate Last Rotation Into This One
	Matrix4fSetRotationFromMatrix3f(&Transform, &ThisRot);	// Set Our Final Transform's Rotation From This One

}

// Code for deforming the mesh 'initialObject' based on the current interpolation functions (global variables). 
// The deformed vertex positions will be stored in the mesh 'res'
// The triangle connectivity is assumed to be already correct in 'res'  

void idle()
{
	static float time = 0;

	time = time + 0.06;
	const float timeOffset = 1.3f*M_PI/numControlPoints;
	//const float displacementMagnitude = 0.1*boundingSphere.radius;
	const float displacementMagnitude = 0.2;

	// move control points
	for (unsigned int i = 0; i<numControlPoints; i++ )
	{
		controlPointDisplacementX[i] = displacementMagnitude*cosf(time+i*timeOffset);
		controlPointDisplacementY[i] = displacementMagnitude*sinf(2.0f*(time+i*timeOffset));
		controlPointDisplacementZ[i] = displacementMagnitude*sinf(4.0f*(time+i*timeOffset));
	}

	// update the control points based on the new control point positions
	RBFWapper::getInstance()->idle(
		controlPointDisplacementX, 
		controlPointDisplacementY,
		controlPointDisplacementZ
		);



}
void glutDisplay(void)
{
	glClearColor(1,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				// Clear Screen And Depth Buffer
 	glLoadIdentity();												// Reset The Current Modelview Matrix

	glTranslatef(-0.0f,0.0f, -30.5f);
    glPushMatrix();
    glMultMatrixf(Transform.M);

#ifdef _Render_Control_Point_
	glScalef(10.0/boundingSphere.radius,10.0/boundingSphere.radius,10.0/boundingSphere.radius);
	glTranslatef(-boundingSphere.center[0],-boundingSphere.center[1],-boundingSphere.center[2]);
//	printf("radius=%f\n", boundingSphere.radius);
//	printf("center=%f, %f, %f\n\n", boundingSphere.center[0],boundingSphere.center[1],boundingSphere.center[2]);

#else
	glScalef(10.0/5.0f , 10.0/5.0f , 10.0/5.0f );
	glTranslatef(192.0f, 192.0f, 192.0f);

#endif
	glColor3f(0.75f,0.75f,1.0f);

	// Render the triangle mesh.
	meshRenderer->draw();

	glColor3f(1.0f,0.33f,0.33f);



	// render control points
#ifdef _Render_Control_Point_
	for (unsigned int i = 0; i<numControlPoints; i++ )
	{
		glPushMatrix();
		glTranslatef(
			RBFWapper::getInstance()->controlPointPosX[i]+controlPointDisplacementX[i],
			RBFWapper::getInstance()->controlPointPosY[i]+controlPointDisplacementY[i],
			RBFWapper::getInstance()->controlPointPosZ[i]+controlPointDisplacementZ[i]
		);
		myQuad=gluNewQuadric();
		gluSphere( myQuad , 0.05*boundingSphere.radius , 15, 15 );
		glPopMatrix();
	} 
#endif

    glPopMatrix();													
	glutSwapBuffers();
	glutPostRedisplay();
}

void glutKeyboard (unsigned char key, int x, int y)
{ 
    switch (key)
    {
		case 'q':
		case 'Q':
			exit (1);
			break;
		case 'n':
			//normalUpdatesDesired = !normalUpdatesDesired;
			break;  
    }
    glutPostRedisplay ();
}


void loadMeshAndSetupControlPoints()
{
	// open an OBJ file to deform
	RBFWapper::getInstance()->loadMesh("test_dragon.obj");

#ifdef _Render_Control_Point_
	boundingSphere = RBFWapper::getInstance()->undeformedMesh->getBoundingSphere();
#endif

	// set up a renderer for the mesh 
	meshRenderer = new RenderTriangleMesh(*(RBFWapper::getInstance()->deformedMesh));

	// we want 11 control points which we place at different vertex positions


	//const int verticesPerControlPoint = ((int)undeformedMesh->getParticles().size())/numControlPoints;
	const int verticesPerControlPoint = 400;

	for (int i = 0; i<numControlPoints; i++)
	{
		RBFWapper::getInstance()->addControlPoint(i*verticesPerControlPoint);
	}
	// allocate vectors for storing displacements
	for (unsigned int i = 0; i<numControlPoints;  i++)
	{
		controlPointDisplacementX.push_back(0.0f);
		controlPointDisplacementY.push_back(0.0f);
		controlPointDisplacementZ.push_back(0.0f);
	}

	RBFWapper::getInstance()->initInterpolationFunction(
		controlPointDisplacementX,
		controlPointDisplacementY,
		controlPointDisplacementZ);

}	


int main(int argc, char** argv)
{

	glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowPosition( GL_WIN_INITIAL_X, GL_WIN_INITIAL_Y );
    glutInitWindowSize( GL_WIN_WIDTH, GL_WIN_HEIGHT );
    glutInit( &argc, argv );

	glutCreateWindow("cg.alexandra.dk tutorial: deformation of geometry by radial basis functions");

	InitializeGlew();

	loadMeshAndSetupControlPoints();

    /*
       The function below are called when the respective event
       is triggered.
    */
    glutReshapeFunc(glutResize);       // called every time  the screen is resized
    glutDisplayFunc(glutDisplay);      // called when window needs to be redisplayed
    glutKeyboardFunc(glutKeyboard);    // called when the application receives a input from the keyboard
    glutMouseFunc(glutMouse);          // called when the application receives a input from the mouse
    glutMotionFunc(glutMotion);        // called when the mouse moves over the screen with one of this button pressed
	glutIdleFunc(idle);
	/*
        Do lighting, material, etc initialization or
        configuration here.
    */
    InitializeOpenGL();

	/*
       Application's main loop. All the above functions
	 are called whe the respective events are triggered
    */
	glutMainLoop();

	RBFWapper::destroy();
}
  