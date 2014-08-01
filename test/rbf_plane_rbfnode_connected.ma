//Maya ASCII 2009 scene
//Name: rbf_plane_rbfnode_connected.ma
//Last modified: Thu, Mar 11, 2010 11:06:21 AM
//Codeset: 936
requires maya "2009";
requires "rbf_d" "1.0";
currentUnit -l centimeter -a degree -t film;
fileInfo "application" "maya";
fileInfo "product" "Maya Unlimited 2009";
fileInfo "version" "2009";
fileInfo "cutIdentifier" "200809110030-734661";
fileInfo "osv" "Microsoft Windows XP Service Pack 2 (Build 2600)\n";
createNode transform -s -n "persp";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 42.816664209878738 48.090576392956692 3.4092949738042146 ;
	setAttr ".r" -type "double3" -54.464389682740119 87.799999999993986 1.6570649677888603e-013 ;
	setAttr ".rp" -type "double3" -7.7715611723760958e-016 -8.8817841970012523e-016 
		0 ;
	setAttr ".rpt" -type "double3" 2.8229133338900448e-015 5.3990931504036212e-016 1.546215833946857e-015 ;
createNode camera -s -n "perspShape" -p "persp";
	setAttr -k off ".v" no;
	setAttr ".fl" 34.999999999999979;
	setAttr ".coi" 66.95581144160117;
	setAttr ".imn" -type "string" "persp";
	setAttr ".den" -type "string" "persp_depth";
	setAttr ".man" -type "string" "persp_mask";
	setAttr ".tp" -type "double3" -5.7657987649115476 -1.4210854715202004e-014 -4.8654718548500053 ;
	setAttr ".hc" -type "string" "viewSet -p %camera";
createNode transform -s -n "top";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 100.1 0 ;
	setAttr ".r" -type "double3" -89.999999999999986 0 0 ;
createNode camera -s -n "topShape" -p "top";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 100.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "top";
	setAttr ".den" -type "string" "top_depth";
	setAttr ".man" -type "string" "top_mask";
	setAttr ".hc" -type "string" "viewSet -t %camera";
	setAttr ".o" yes;
createNode transform -s -n "front";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 0 100.1 ;
createNode camera -s -n "frontShape" -p "front";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 100.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "front";
	setAttr ".den" -type "string" "front_depth";
	setAttr ".man" -type "string" "front_mask";
	setAttr ".hc" -type "string" "viewSet -f %camera";
	setAttr ".o" yes;
createNode transform -s -n "side";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 100.1 0 0 ;
	setAttr ".r" -type "double3" 0 89.999999999999986 0 ;
createNode camera -s -n "sideShape" -p "side";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 100.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "side";
	setAttr ".den" -type "string" "side_depth";
	setAttr ".man" -type "string" "side_mask";
	setAttr ".hc" -type "string" "viewSet -s %camera";
	setAttr ".o" yes;
createNode transform -n "pPlane2";
	setAttr ".t" -type "double3" -5.7657987649115547 0 6.1218304720796528 ;
createNode mesh -n "pPlaneShape2" -p "pPlane2";
	addAttr -ci true -sn "mso" -ln "miShadingSamplesOverride" -min 0 -max 1 -at "bool";
	addAttr -ci true -sn "msh" -ln "miShadingSamples" -min 0 -smx 8 -at "float";
	addAttr -ci true -sn "mdo" -ln "miMaxDisplaceOverride" -min 0 -max 1 -at "bool";
	addAttr -ci true -sn "mmd" -ln "miMaxDisplace" -min 0 -smx 1 -at "float";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 81 ".uvst[0].uvsp[0:80]" -type "float2" 0 0 0.125 0 0.25 
		0 0.375 0 0.5 0 0.625 0 0.75 0 0.875 0 1 0 0 0.092792735 0.125 0.092792735 0.25 0.092792735 
		0.375 0.092792735 0.5 0.092792735 0.625 0.092792735 0.75 0.092792735 0.875 0.092792735 
		1 0.092792735 0 0.18558547 0.125 0.18558547 0.25 0.18558547 0.375 0.18558547 0.5 
		0.18558547 0.625 0.18558547 0.75 0.18558547 0.875 0.18558547 1 0.18558547 0 0.27837819 
		0.125 0.27837819 0.25 0.27837819 0.375 0.27837819 0.5 0.27837819 0.625 0.27837819 
		0.75 0.27837819 0.875 0.27837819 1 0.27837819 0 0.37117094 0.125 0.37117094 0.25 
		0.37117094 0.375 0.37117094 0.5 0.37117094 0.625 0.37117094 0.75 0.37117094 0.875 
		0.37117094 1 0.37117094 0 0.46396369 0.125 0.46396369 0.25 0.46396369 0.375 0.46396369 
		0.5 0.46396369 0.625 0.46396369 0.75 0.46396369 0.875 0.46396369 1 0.46396369 0 0.55675638 
		0.125 0.55675638 0.25 0.55675638 0.375 0.55675638 0.5 0.55675638 0.625 0.55675638 
		0.75 0.55675638 0.875 0.55675638 1 0.55675638 0 0.64954913 0.125 0.64954913 0.25 
		0.64954913 0.375 0.64954913 0.5 0.64954913 0.625 0.64954913 0.75 0.64954913 0.875 
		0.64954913 1 0.64954913 0 0.74234188 0.125 0.74234188 0.25 0.74234188 0.375 0.74234188 
		0.5 0.74234188 0.625 0.74234188 0.75 0.74234188 0.875 0.74234188 1 0.74234188;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 81 ".vt[0:80]"  -5.2155213 -8.5969005e-016 3.8716998 -3.9116411 
		-8.5969005e-016 3.8716998 -2.6077607 -8.5969005e-016 3.8716998 -1.3038802 -8.5969005e-016 
		3.8716998 0 -8.5969005e-016 3.8716998 1.3038802 -8.5969005e-016 3.8716998 2.6077609 
		-8.5969005e-016 3.8716998 3.9116406 -8.5969005e-016 3.8716998 5.2155213 -8.5969005e-016 
		3.8716998 -5.2155213 -6.4476751e-016 2.9037747 -3.9116411 -6.4476751e-016 2.9037747 
		-2.6077607 -6.4476751e-016 2.9037747 -1.3038802 -6.4476751e-016 2.9037747 0 -6.4476751e-016 
		2.9037747 1.3038802 -6.4476751e-016 2.9037747 2.6077609 -6.4476751e-016 2.9037747 
		3.9116406 -6.4476751e-016 2.9037747 5.2155213 -6.4476751e-016 2.9037747 -5.2155213 
		-4.2984503e-016 1.9358499 -3.9116411 -4.2984503e-016 1.9358499 -2.6077607 -4.2984503e-016 
		1.9358499 -1.3038802 -4.2984503e-016 1.9358499 0 -4.2984503e-016 1.9358499 1.3038802 
		-4.2984503e-016 1.9358499 2.6077609 -4.2984503e-016 1.9358499 3.9116406 -4.2984503e-016 
		1.9358499 5.2155213 -4.2984503e-016 1.9358499 -5.2155213 -2.1492254e-016 0.96792507 
		-3.9116411 -2.1492254e-016 0.96792507 -2.6077607 -2.1492254e-016 0.96792507 -1.3038802 
		-2.1492254e-016 0.96792507 0 -2.1492254e-016 0.96792507 1.3038802 -2.1492254e-016 
		0.96792507 2.6077609 -2.1492254e-016 0.96792507 3.9116406 -2.1492254e-016 0.96792507 
		5.2155213 -2.1492254e-016 0.96792507 -5.2155213 0 0 -3.9116411 0 0 -2.6077607 0 0 
		-1.3038802 0 0 0 0 0 1.3038802 0 0 2.6077609 0 0 3.9116406 0 0 5.2155213 0 0 -5.2155213 
		2.1492254e-016 -0.96792507 -3.9116411 2.1492254e-016 -0.96792507 -2.6077607 2.1492254e-016 
		-0.96792507 -1.3038802 2.1492254e-016 -0.96792507 0 2.1492254e-016 -0.96792507 1.3038802 
		2.1492254e-016 -0.96792507 2.6077609 2.1492254e-016 -0.96792507 3.9116406 2.1492254e-016 
		-0.96792507 5.2155213 2.1492254e-016 -0.96792507 -5.2155213 4.2984497e-016 -1.9358497 
		-3.9116411 4.2984497e-016 -1.9358497 -2.6077607 4.2984497e-016 -1.9358497 -1.3038802 
		4.2984497e-016 -1.9358497 0 4.2984497e-016 -1.9358497 1.3038802 4.2984497e-016 -1.9358497 
		2.6077609 4.2984497e-016 -1.9358497 3.9116406 4.2984497e-016 -1.9358497 5.2155213 
		4.2984497e-016 -1.9358497 -5.2155213 6.4476751e-016 -2.9037747 -3.9116411 6.4476751e-016 
		-2.9037747 -2.6077607 6.4476751e-016 -2.9037747 -1.3038802 6.4476751e-016 -2.9037747 
		0 6.4476751e-016 -2.9037747 1.3038802 6.4476751e-016 -2.9037747 2.6077609 6.4476751e-016 
		-2.9037747 3.9116406 6.4476751e-016 -2.9037747 5.2155213 6.4476751e-016 -2.9037747 
		-5.2155213 8.5969005e-016 -3.8716998 -3.9116411 8.5969005e-016 -3.8716998 -2.6077607 
		8.5969005e-016 -3.8716998 -1.3038802 8.5969005e-016 -3.8716998 0 8.5969005e-016 -3.8716998 
		1.3038802 8.5969005e-016 -3.8716998 2.6077609 8.5969005e-016 -3.8716998 3.9116406 
		8.5969005e-016 -3.8716998 5.2155213 8.5969005e-016 -3.8716998;
	setAttr -s 144 ".ed[0:143]"  0 1 0 0 9 0 
		1 2 0 1 10 1 2 3 0 2 11 1 
		3 4 0 3 12 1 4 5 0 4 13 1 
		5 6 0 5 14 1 6 7 0 6 15 1 
		7 8 0 7 16 1 8 17 0 9 10 1 
		9 18 0 10 11 1 10 19 1 11 12 1 
		11 20 1 12 13 1 12 21 1 13 14 1 
		13 22 1 14 15 1 14 23 1 15 16 1 
		15 24 1 16 17 1 16 25 1 17 26 0 
		18 19 1 18 27 0 19 20 1 19 28 1 
		20 21 1 20 29 1 21 22 1 21 30 1 
		22 23 1 22 31 1 23 24 1 23 32 1 
		24 25 1 24 33 1 25 26 1 25 34 1 
		26 35 0 27 28 1 27 36 0 28 29 1 
		28 37 1 29 30 1 29 38 1 30 31 1 
		30 39 1 31 32 1 31 40 1 32 33 1 
		32 41 1 33 34 1 33 42 1 34 35 1 
		34 43 1 35 44 0 36 37 1 36 45 0 
		37 38 1 37 46 1 38 39 1 38 47 1 
		39 40 1 39 48 1 40 41 1 40 49 1 
		41 42 1 41 50 1 42 43 1 42 51 1 
		43 44 1 43 52 1 44 53 0 45 46 1 
		45 54 0 46 47 1 46 55 1 47 48 1 
		47 56 1 48 49 1 48 57 1 49 50 1 
		49 58 1 50 51 1 50 59 1 51 52 1 
		51 60 1 52 53 1 52 61 1 53 62 0 
		54 55 1 54 63 0 55 56 1 55 64 1 
		56 57 1 56 65 1 57 58 1 57 66 1 
		58 59 1 58 67 1 59 60 1 59 68 1 
		60 61 1 60 69 1 61 62 1 61 70 1 
		62 71 0 63 64 1 63 72 0 64 65 1 
		64 73 1 65 66 1 65 74 1 66 67 1 
		66 75 1 67 68 1 67 76 1 68 69 1 
		68 77 1 69 70 1 69 78 1 70 71 1 
		70 79 1 71 80 0 72 73 0 73 74 0 
		74 75 0 75 76 0 76 77 0 77 78 0 
		78 79 0 79 80 0;
	setAttr -s 64 ".fc[0:63]" -type "polyFaces" 
		f 4 0 3 -18 -2 
		mu 0 4 0 1 10 9 
		f 4 2 5 -20 -4 
		mu 0 4 1 2 11 10 
		f 4 4 7 -22 -6 
		mu 0 4 2 3 12 11 
		f 4 6 9 -24 -8 
		mu 0 4 3 4 13 12 
		f 4 8 11 -26 -10 
		mu 0 4 4 5 14 13 
		f 4 10 13 -28 -12 
		mu 0 4 5 6 15 14 
		f 4 12 15 -30 -14 
		mu 0 4 6 7 16 15 
		f 4 14 16 -32 -16 
		mu 0 4 7 8 17 16 
		f 4 17 20 -35 -19 
		mu 0 4 9 10 19 18 
		f 4 19 22 -37 -21 
		mu 0 4 10 11 20 19 
		f 4 21 24 -39 -23 
		mu 0 4 11 12 21 20 
		f 4 23 26 -41 -25 
		mu 0 4 12 13 22 21 
		f 4 25 28 -43 -27 
		mu 0 4 13 14 23 22 
		f 4 27 30 -45 -29 
		mu 0 4 14 15 24 23 
		f 4 29 32 -47 -31 
		mu 0 4 15 16 25 24 
		f 4 31 33 -49 -33 
		mu 0 4 16 17 26 25 
		f 4 34 37 -52 -36 
		mu 0 4 18 19 28 27 
		f 4 36 39 -54 -38 
		mu 0 4 19 20 29 28 
		f 4 38 41 -56 -40 
		mu 0 4 20 21 30 29 
		f 4 40 43 -58 -42 
		mu 0 4 21 22 31 30 
		f 4 42 45 -60 -44 
		mu 0 4 22 23 32 31 
		f 4 44 47 -62 -46 
		mu 0 4 23 24 33 32 
		f 4 46 49 -64 -48 
		mu 0 4 24 25 34 33 
		f 4 48 50 -66 -50 
		mu 0 4 25 26 35 34 
		f 4 51 54 -69 -53 
		mu 0 4 27 28 37 36 
		f 4 53 56 -71 -55 
		mu 0 4 28 29 38 37 
		f 4 55 58 -73 -57 
		mu 0 4 29 30 39 38 
		f 4 57 60 -75 -59 
		mu 0 4 30 31 40 39 
		f 4 59 62 -77 -61 
		mu 0 4 31 32 41 40 
		f 4 61 64 -79 -63 
		mu 0 4 32 33 42 41 
		f 4 63 66 -81 -65 
		mu 0 4 33 34 43 42 
		f 4 65 67 -83 -67 
		mu 0 4 34 35 44 43 
		f 4 68 71 -86 -70 
		mu 0 4 36 37 46 45 
		f 4 70 73 -88 -72 
		mu 0 4 37 38 47 46 
		f 4 72 75 -90 -74 
		mu 0 4 38 39 48 47 
		f 4 74 77 -92 -76 
		mu 0 4 39 40 49 48 
		f 4 76 79 -94 -78 
		mu 0 4 40 41 50 49 
		f 4 78 81 -96 -80 
		mu 0 4 41 42 51 50 
		f 4 80 83 -98 -82 
		mu 0 4 42 43 52 51 
		f 4 82 84 -100 -84 
		mu 0 4 43 44 53 52 
		f 4 85 88 -103 -87 
		mu 0 4 45 46 55 54 
		f 4 87 90 -105 -89 
		mu 0 4 46 47 56 55 
		f 4 89 92 -107 -91 
		mu 0 4 47 48 57 56 
		f 4 91 94 -109 -93 
		mu 0 4 48 49 58 57 
		f 4 93 96 -111 -95 
		mu 0 4 49 50 59 58 
		f 4 95 98 -113 -97 
		mu 0 4 50 51 60 59 
		f 4 97 100 -115 -99 
		mu 0 4 51 52 61 60 
		f 4 99 101 -117 -101 
		mu 0 4 52 53 62 61 
		f 4 102 105 -120 -104 
		mu 0 4 54 55 64 63 
		f 4 104 107 -122 -106 
		mu 0 4 55 56 65 64 
		f 4 106 109 -124 -108 
		mu 0 4 56 57 66 65 
		f 4 108 111 -126 -110 
		mu 0 4 57 58 67 66 
		f 4 110 113 -128 -112 
		mu 0 4 58 59 68 67 
		f 4 112 115 -130 -114 
		mu 0 4 59 60 69 68 
		f 4 114 117 -132 -116 
		mu 0 4 60 61 70 69 
		f 4 116 118 -134 -118 
		mu 0 4 61 62 71 70 
		f 4 119 122 -137 -121 
		mu 0 4 63 64 73 72 
		f 4 121 124 -138 -123 
		mu 0 4 64 65 74 73 
		f 4 123 126 -139 -125 
		mu 0 4 65 66 75 74 
		f 4 125 128 -140 -127 
		mu 0 4 66 67 76 75 
		f 4 127 130 -141 -129 
		mu 0 4 67 68 77 76 
		f 4 129 132 -142 -131 
		mu 0 4 68 69 78 77 
		f 4 131 134 -143 -133 
		mu 0 4 69 70 79 78 
		f 4 133 135 -144 -135 
		mu 0 4 70 71 80 79 ;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
createNode transform -n "pPlane3";
	setAttr ".t" -type "double3" -5.7657987649115547 0 -4.8654718548500018 ;
createNode mesh -n "pPlaneShape3" -p "pPlane3";
	addAttr -ci true -sn "mso" -ln "miShadingSamplesOverride" -min 0 -max 1 -at "bool";
	addAttr -ci true -sn "msh" -ln "miShadingSamples" -min 0 -smx 8 -at "float";
	addAttr -ci true -sn "mdo" -ln "miMaxDisplaceOverride" -min 0 -max 1 -at "bool";
	addAttr -ci true -sn "mmd" -ln "miMaxDisplace" -min 0 -smx 1 -at "float";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 81 ".uvst[0].uvsp[0:80]" -type "float2" 0 0 0.125 0 0.25 
		0 0.375 0 0.5 0 0.625 0 0.75 0 0.875 0 1 0 0 0.092792735 0.125 0.092792735 0.25 0.092792735 
		0.375 0.092792735 0.5 0.092792735 0.625 0.092792735 0.75 0.092792735 0.875 0.092792735 
		1 0.092792735 0 0.18558547 0.125 0.18558547 0.25 0.18558547 0.375 0.18558547 0.5 
		0.18558547 0.625 0.18558547 0.75 0.18558547 0.875 0.18558547 1 0.18558547 0 0.27837819 
		0.125 0.27837819 0.25 0.27837819 0.375 0.27837819 0.5 0.27837819 0.625 0.27837819 
		0.75 0.27837819 0.875 0.27837819 1 0.27837819 0 0.37117094 0.125 0.37117094 0.25 
		0.37117094 0.375 0.37117094 0.5 0.37117094 0.625 0.37117094 0.75 0.37117094 0.875 
		0.37117094 1 0.37117094 0 0.46396369 0.125 0.46396369 0.25 0.46396369 0.375 0.46396369 
		0.5 0.46396369 0.625 0.46396369 0.75 0.46396369 0.875 0.46396369 1 0.46396369 0 0.55675638 
		0.125 0.55675638 0.25 0.55675638 0.375 0.55675638 0.5 0.55675638 0.625 0.55675638 
		0.75 0.55675638 0.875 0.55675638 1 0.55675638 0 0.64954913 0.125 0.64954913 0.25 
		0.64954913 0.375 0.64954913 0.5 0.64954913 0.625 0.64954913 0.75 0.64954913 0.875 
		0.64954913 1 0.64954913 0 0.74234188 0.125 0.74234188 0.25 0.74234188 0.375 0.74234188 
		0.5 0.74234188 0.625 0.74234188 0.75 0.74234188 0.875 0.74234188 1 0.74234188;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 20 ".pt";
	setAttr ".pt[21:23]" -type "float3" 0 -0.76397872 -2.220446e-016  0 -0.99474514 
		-2.220446e-016  0 -0.89039022 -2.220446e-016 ;
	setAttr ".pt[29:33]" -type "float3" 0 -0.47572404 -1.110223e-016  0 -1 -2.220446e-016  
		0 -1 -2.220446e-016  0 -1 -2.220446e-016  0 -0.60508579 -1.110223e-016 ;
	setAttr ".pt[38:42]" -type "float3" 0 -0.44256264 -9.8268646e-017  0 -0.99999261 
		-2.2204296e-016  -1.4287314e-006 -1.9999526 -0.0097482502  0 -1 -2.220446e-016  0 
		-0.99302757 -2.2049644e-016 ;
	setAttr ".pt[48:51]" -type "float3" 0 -0.99999988 -2.220446e-016  -0.0015168271 
		-1.0602565 -0.0020495842  0 -1 -2.220446e-016  0 -0.75946337 -2.220446e-016 ;
	setAttr ".pt[57:59]" -type "float3" 0 -0.83807045 -2.220446e-016  0 -0.99999994 
		-2.220446e-016  0 -0.99974436 -2.220446e-016 ;
	setAttr -s 81 ".vt[0:80]"  -5.2155213 -8.5969005e-016 3.8716998 -3.9116411 
		-8.5969005e-016 3.8716998 -2.6077607 -8.5969005e-016 3.8716998 -1.3038802 -8.5969005e-016 
		3.8716998 0 -8.5969005e-016 3.8716998 1.3038802 -8.5969005e-016 3.8716998 2.6077609 
		-8.5969005e-016 3.8716998 3.9116406 -8.5969005e-016 3.8716998 5.2155213 -8.5969005e-016 
		3.8716998 -5.2155213 -6.4476751e-016 2.9037747 -3.9116411 -6.4476751e-016 2.9037747 
		-2.6077607 -6.4476751e-016 2.9037747 -1.3038802 -6.4476751e-016 2.9037747 0 -6.4476751e-016 
		2.9037747 1.3038802 -6.4476751e-016 2.9037747 2.6077609 -6.4476751e-016 2.9037747 
		3.9116406 -6.4476751e-016 2.9037747 5.2155213 -6.4476751e-016 2.9037747 -5.2155213 
		-4.2984503e-016 1.9358499 -3.9116411 -4.2984503e-016 1.9358499 -2.6077607 -4.2984503e-016 
		1.9358499 -1.3038802 -4.2984503e-016 1.9358499 0 -4.2984503e-016 1.9358499 1.3038802 
		-4.2984503e-016 1.9358499 2.6077609 -4.2984503e-016 1.9358499 3.9116406 -4.2984503e-016 
		1.9358499 5.2155213 -4.2984503e-016 1.9358499 -5.2155213 -2.1492254e-016 0.96792507 
		-3.9116411 -2.1492254e-016 0.96792507 -2.6077607 -2.1492254e-016 0.96792507 -1.3038802 
		-2.1492254e-016 0.96792507 0 -2.1492254e-016 0.96792507 1.3038802 -2.1492254e-016 
		0.96792507 2.6077609 -2.1492254e-016 0.96792507 3.9116406 -2.1492254e-016 0.96792507 
		5.2155213 -2.1492254e-016 0.96792507 -5.2155213 0 0 -3.9116411 0 0 -2.6077607 0 0 
		-1.3038802 0 0 0 0 0 1.3038802 0 0 2.6077609 0 0 3.9116406 0 0 5.2155213 0 0 -5.2155213 
		2.1492254e-016 -0.96792507 -3.9116411 2.1492254e-016 -0.96792507 -2.6077607 2.1492254e-016 
		-0.96792507 -1.3038802 2.1492254e-016 -0.96792507 0 2.1492254e-016 -0.96792507 1.3038802 
		2.1492254e-016 -0.96792507 2.6077609 2.1492254e-016 -0.96792507 3.9116406 2.1492254e-016 
		-0.96792507 5.2155213 2.1492254e-016 -0.96792507 -5.2155213 4.2984497e-016 -1.9358497 
		-3.9116411 4.2984497e-016 -1.9358497 -2.6077607 4.2984497e-016 -1.9358497 -1.3038802 
		4.2984497e-016 -1.9358497 0 4.2984497e-016 -1.9358497 1.3038802 4.2984497e-016 -1.9358497 
		2.6077609 4.2984497e-016 -1.9358497 3.9116406 4.2984497e-016 -1.9358497 5.2155213 
		4.2984497e-016 -1.9358497 -5.2155213 6.4476751e-016 -2.9037747 -3.9116411 6.4476751e-016 
		-2.9037747 -2.6077607 6.4476751e-016 -2.9037747 -1.3038802 6.4476751e-016 -2.9037747 
		0 6.4476751e-016 -2.9037747 1.3038802 6.4476751e-016 -2.9037747 2.6077609 6.4476751e-016 
		-2.9037747 3.9116406 6.4476751e-016 -2.9037747 5.2155213 6.4476751e-016 -2.9037747 
		-5.2155213 8.5969005e-016 -3.8716998 -3.9116411 8.5969005e-016 -3.8716998 -2.6077607 
		8.5969005e-016 -3.8716998 -1.3038802 8.5969005e-016 -3.8716998 0 8.5969005e-016 -3.8716998 
		1.3038802 8.5969005e-016 -3.8716998 2.6077609 8.5969005e-016 -3.8716998 3.9116406 
		8.5969005e-016 -3.8716998 5.2155213 8.5969005e-016 -3.8716998;
	setAttr -s 144 ".ed[0:143]"  0 1 0 0 9 0 
		1 2 0 1 10 1 2 3 0 2 11 1 
		3 4 0 3 12 1 4 5 0 4 13 1 
		5 6 0 5 14 1 6 7 0 6 15 1 
		7 8 0 7 16 1 8 17 0 9 10 1 
		9 18 0 10 11 1 10 19 1 11 12 1 
		11 20 1 12 13 1 12 21 1 13 14 1 
		13 22 1 14 15 1 14 23 1 15 16 1 
		15 24 1 16 17 1 16 25 1 17 26 0 
		18 19 1 18 27 0 19 20 1 19 28 1 
		20 21 1 20 29 1 21 22 1 21 30 1 
		22 23 1 22 31 1 23 24 1 23 32 1 
		24 25 1 24 33 1 25 26 1 25 34 1 
		26 35 0 27 28 1 27 36 0 28 29 1 
		28 37 1 29 30 1 29 38 1 30 31 1 
		30 39 1 31 32 1 31 40 1 32 33 1 
		32 41 1 33 34 1 33 42 1 34 35 1 
		34 43 1 35 44 0 36 37 1 36 45 0 
		37 38 1 37 46 1 38 39 1 38 47 1 
		39 40 1 39 48 1 40 41 1 40 49 1 
		41 42 1 41 50 1 42 43 1 42 51 1 
		43 44 1 43 52 1 44 53 0 45 46 1 
		45 54 0 46 47 1 46 55 1 47 48 1 
		47 56 1 48 49 1 48 57 1 49 50 1 
		49 58 1 50 51 1 50 59 1 51 52 1 
		51 60 1 52 53 1 52 61 1 53 62 0 
		54 55 1 54 63 0 55 56 1 55 64 1 
		56 57 1 56 65 1 57 58 1 57 66 1 
		58 59 1 58 67 1 59 60 1 59 68 1 
		60 61 1 60 69 1 61 62 1 61 70 1 
		62 71 0 63 64 1 63 72 0 64 65 1 
		64 73 1 65 66 1 65 74 1 66 67 1 
		66 75 1 67 68 1 67 76 1 68 69 1 
		68 77 1 69 70 1 69 78 1 70 71 1 
		70 79 1 71 80 0 72 73 0 73 74 0 
		74 75 0 75 76 0 76 77 0 77 78 0 
		78 79 0 79 80 0;
	setAttr -s 64 ".fc[0:63]" -type "polyFaces" 
		f 4 0 3 -18 -2 
		mu 0 4 0 1 10 9 
		f 4 2 5 -20 -4 
		mu 0 4 1 2 11 10 
		f 4 4 7 -22 -6 
		mu 0 4 2 3 12 11 
		f 4 6 9 -24 -8 
		mu 0 4 3 4 13 12 
		f 4 8 11 -26 -10 
		mu 0 4 4 5 14 13 
		f 4 10 13 -28 -12 
		mu 0 4 5 6 15 14 
		f 4 12 15 -30 -14 
		mu 0 4 6 7 16 15 
		f 4 14 16 -32 -16 
		mu 0 4 7 8 17 16 
		f 4 17 20 -35 -19 
		mu 0 4 9 10 19 18 
		f 4 19 22 -37 -21 
		mu 0 4 10 11 20 19 
		f 4 21 24 -39 -23 
		mu 0 4 11 12 21 20 
		f 4 23 26 -41 -25 
		mu 0 4 12 13 22 21 
		f 4 25 28 -43 -27 
		mu 0 4 13 14 23 22 
		f 4 27 30 -45 -29 
		mu 0 4 14 15 24 23 
		f 4 29 32 -47 -31 
		mu 0 4 15 16 25 24 
		f 4 31 33 -49 -33 
		mu 0 4 16 17 26 25 
		f 4 34 37 -52 -36 
		mu 0 4 18 19 28 27 
		f 4 36 39 -54 -38 
		mu 0 4 19 20 29 28 
		f 4 38 41 -56 -40 
		mu 0 4 20 21 30 29 
		f 4 40 43 -58 -42 
		mu 0 4 21 22 31 30 
		f 4 42 45 -60 -44 
		mu 0 4 22 23 32 31 
		f 4 44 47 -62 -46 
		mu 0 4 23 24 33 32 
		f 4 46 49 -64 -48 
		mu 0 4 24 25 34 33 
		f 4 48 50 -66 -50 
		mu 0 4 25 26 35 34 
		f 4 51 54 -69 -53 
		mu 0 4 27 28 37 36 
		f 4 53 56 -71 -55 
		mu 0 4 28 29 38 37 
		f 4 55 58 -73 -57 
		mu 0 4 29 30 39 38 
		f 4 57 60 -75 -59 
		mu 0 4 30 31 40 39 
		f 4 59 62 -77 -61 
		mu 0 4 31 32 41 40 
		f 4 61 64 -79 -63 
		mu 0 4 32 33 42 41 
		f 4 63 66 -81 -65 
		mu 0 4 33 34 43 42 
		f 4 65 67 -83 -67 
		mu 0 4 34 35 44 43 
		f 4 68 71 -86 -70 
		mu 0 4 36 37 46 45 
		f 4 70 73 -88 -72 
		mu 0 4 37 38 47 46 
		f 4 72 75 -90 -74 
		mu 0 4 38 39 48 47 
		f 4 74 77 -92 -76 
		mu 0 4 39 40 49 48 
		f 4 76 79 -94 -78 
		mu 0 4 40 41 50 49 
		f 4 78 81 -96 -80 
		mu 0 4 41 42 51 50 
		f 4 80 83 -98 -82 
		mu 0 4 42 43 52 51 
		f 4 82 84 -100 -84 
		mu 0 4 43 44 53 52 
		f 4 85 88 -103 -87 
		mu 0 4 45 46 55 54 
		f 4 87 90 -105 -89 
		mu 0 4 46 47 56 55 
		f 4 89 92 -107 -91 
		mu 0 4 47 48 57 56 
		f 4 91 94 -109 -93 
		mu 0 4 48 49 58 57 
		f 4 93 96 -111 -95 
		mu 0 4 49 50 59 58 
		f 4 95 98 -113 -97 
		mu 0 4 50 51 60 59 
		f 4 97 100 -115 -99 
		mu 0 4 51 52 61 60 
		f 4 99 101 -117 -101 
		mu 0 4 52 53 62 61 
		f 4 102 105 -120 -104 
		mu 0 4 54 55 64 63 
		f 4 104 107 -122 -106 
		mu 0 4 55 56 65 64 
		f 4 106 109 -124 -108 
		mu 0 4 56 57 66 65 
		f 4 108 111 -126 -110 
		mu 0 4 57 58 67 66 
		f 4 110 113 -128 -112 
		mu 0 4 58 59 68 67 
		f 4 112 115 -130 -114 
		mu 0 4 59 60 69 68 
		f 4 114 117 -132 -116 
		mu 0 4 60 61 70 69 
		f 4 116 118 -134 -118 
		mu 0 4 61 62 71 70 
		f 4 119 122 -137 -121 
		mu 0 4 63 64 73 72 
		f 4 121 124 -138 -123 
		mu 0 4 64 65 74 73 
		f 4 123 126 -139 -125 
		mu 0 4 65 66 75 74 
		f 4 125 128 -140 -127 
		mu 0 4 66 67 76 75 
		f 4 127 130 -141 -129 
		mu 0 4 67 68 77 76 
		f 4 129 132 -142 -131 
		mu 0 4 68 69 78 77 
		f 4 131 134 -143 -133 
		mu 0 4 69 70 79 78 
		f 4 133 135 -144 -135 
		mu 0 4 70 71 80 79 ;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
createNode transform -n "pPlane4";
	setAttr ".t" -type "double3" 13.207301248210669 0 0.19495359643282484 ;
createNode mesh -n "pPlaneShape4" -p "pPlane4";
	addAttr -ci true -sn "mso" -ln "miShadingSamplesOverride" -min 0 -max 1 -at "bool";
	addAttr -ci true -sn "msh" -ln "miShadingSamples" -min 0 -smx 8 -at "float";
	addAttr -ci true -sn "mdo" -ln "miMaxDisplaceOverride" -min 0 -max 1 -at "bool";
	addAttr -ci true -sn "mmd" -ln "miMaxDisplace" -min 0 -smx 1 -at "float";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 81 ".uvst[0].uvsp[0:80]" -type "float2" 0 0 0.125 0 0.25 
		0 0.375 0 0.5 0 0.625 0 0.75 0 0.875 0 1 0 0 0.092792735 0.125 0.092792735 0.25 0.092792735 
		0.375 0.092792735 0.5 0.092792735 0.625 0.092792735 0.75 0.092792735 0.875 0.092792735 
		1 0.092792735 0 0.18558547 0.125 0.18558547 0.25 0.18558547 0.375 0.18558547 0.5 
		0.18558547 0.625 0.18558547 0.75 0.18558547 0.875 0.18558547 1 0.18558547 0 0.27837819 
		0.125 0.27837819 0.25 0.27837819 0.375 0.27837819 0.5 0.27837819 0.625 0.27837819 
		0.75 0.27837819 0.875 0.27837819 1 0.27837819 0 0.37117094 0.125 0.37117094 0.25 
		0.37117094 0.375 0.37117094 0.5 0.37117094 0.625 0.37117094 0.75 0.37117094 0.875 
		0.37117094 1 0.37117094 0 0.46396369 0.125 0.46396369 0.25 0.46396369 0.375 0.46396369 
		0.5 0.46396369 0.625 0.46396369 0.75 0.46396369 0.875 0.46396369 1 0.46396369 0 0.55675638 
		0.125 0.55675638 0.25 0.55675638 0.375 0.55675638 0.5 0.55675638 0.625 0.55675638 
		0.75 0.55675638 0.875 0.55675638 1 0.55675638 0 0.64954913 0.125 0.64954913 0.25 
		0.64954913 0.375 0.64954913 0.5 0.64954913 0.625 0.64954913 0.75 0.64954913 0.875 
		0.64954913 1 0.64954913 0 0.74234188 0.125 0.74234188 0.25 0.74234188 0.375 0.74234188 
		0.5 0.74234188 0.625 0.74234188 0.75 0.74234188 0.875 0.74234188 1 0.74234188;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 81 ".vt[0:80]"  -5.2155213 -8.5969005e-016 3.8716998 -3.9116411 
		-8.5969005e-016 3.8716998 -2.6077607 -8.5969005e-016 3.8716998 -1.3038802 -8.5969005e-016 
		3.8716998 0 -8.5969005e-016 3.8716998 1.3038802 -8.5969005e-016 3.8716998 2.6077609 
		-8.5969005e-016 3.8716998 3.9116406 -8.5969005e-016 3.8716998 5.2155213 -8.5969005e-016 
		3.8716998 -5.2155213 -6.4476751e-016 2.9037747 -3.9116411 -6.4476751e-016 2.9037747 
		-2.6077607 -6.4476751e-016 2.9037747 -1.3038802 -6.4476751e-016 2.9037747 0 -6.4476751e-016 
		2.9037747 1.3038802 -6.4476751e-016 2.9037747 2.6077609 -6.4476751e-016 2.9037747 
		3.9116406 -6.4476751e-016 2.9037747 5.2155213 -6.4476751e-016 2.9037747 -5.2155213 
		-4.2984503e-016 1.9358499 -3.9116411 -4.2984503e-016 1.9358499 -2.6077607 -4.2984503e-016 
		1.9358499 -1.3038802 -4.2984503e-016 1.9358499 0 -4.2984503e-016 1.9358499 1.3038802 
		-4.2984503e-016 1.9358499 2.6077609 -4.2984503e-016 1.9358499 3.9116406 -4.2984503e-016 
		1.9358499 5.2155213 -4.2984503e-016 1.9358499 -5.2155213 -2.1492254e-016 0.96792507 
		-3.9116411 -2.1492254e-016 0.96792507 -2.6077607 -2.1492254e-016 0.96792507 -1.3038802 
		-2.1492254e-016 0.96792507 0 -2.1492254e-016 0.96792507 1.3038802 -2.1492254e-016 
		0.96792507 2.6077609 -2.1492254e-016 0.96792507 3.9116406 -2.1492254e-016 0.96792507 
		5.2155213 -2.1492254e-016 0.96792507 -5.2155213 0 0 -3.9116411 0 0 -2.6077607 0 0 
		-1.3038802 0 0 0 0 0 1.3038802 0 0 2.6077609 0 0 3.9116406 0 0 5.2155213 0 0 -5.2155213 
		2.1492254e-016 -0.96792507 -3.9116411 2.1492254e-016 -0.96792507 -2.6077607 2.1492254e-016 
		-0.96792507 -1.3038802 2.1492254e-016 -0.96792507 0 2.1492254e-016 -0.96792507 1.3038802 
		2.1492254e-016 -0.96792507 2.6077609 2.1492254e-016 -0.96792507 3.9116406 2.1492254e-016 
		-0.96792507 5.2155213 2.1492254e-016 -0.96792507 -5.2155213 4.2984497e-016 -1.9358497 
		-3.9116411 4.2984497e-016 -1.9358497 -2.6077607 4.2984497e-016 -1.9358497 -1.3038802 
		4.2984497e-016 -1.9358497 0 4.2984497e-016 -1.9358497 1.3038802 4.2984497e-016 -1.9358497 
		2.6077609 4.2984497e-016 -1.9358497 3.9116406 4.2984497e-016 -1.9358497 5.2155213 
		4.2984497e-016 -1.9358497 -5.2155213 6.4476751e-016 -2.9037747 -3.9116411 6.4476751e-016 
		-2.9037747 -2.6077607 6.4476751e-016 -2.9037747 -1.3038802 6.4476751e-016 -2.9037747 
		0 6.4476751e-016 -2.9037747 1.3038802 6.4476751e-016 -2.9037747 2.6077609 6.4476751e-016 
		-2.9037747 3.9116406 6.4476751e-016 -2.9037747 5.2155213 6.4476751e-016 -2.9037747 
		-5.2155213 8.5969005e-016 -3.8716998 -3.9116411 8.5969005e-016 -3.8716998 -2.6077607 
		8.5969005e-016 -3.8716998 -1.3038802 8.5969005e-016 -3.8716998 0 8.5969005e-016 -3.8716998 
		1.3038802 8.5969005e-016 -3.8716998 2.6077609 8.5969005e-016 -3.8716998 3.9116406 
		8.5969005e-016 -3.8716998 5.2155213 8.5969005e-016 -3.8716998;
	setAttr -s 144 ".ed[0:143]"  0 1 0 0 9 0 
		1 2 0 1 10 1 2 3 0 2 11 1 
		3 4 0 3 12 1 4 5 0 4 13 1 
		5 6 0 5 14 1 6 7 0 6 15 1 
		7 8 0 7 16 1 8 17 0 9 10 1 
		9 18 0 10 11 1 10 19 1 11 12 1 
		11 20 1 12 13 1 12 21 1 13 14 1 
		13 22 1 14 15 1 14 23 1 15 16 1 
		15 24 1 16 17 1 16 25 1 17 26 0 
		18 19 1 18 27 0 19 20 1 19 28 1 
		20 21 1 20 29 1 21 22 1 21 30 1 
		22 23 1 22 31 1 23 24 1 23 32 1 
		24 25 1 24 33 1 25 26 1 25 34 1 
		26 35 0 27 28 1 27 36 0 28 29 1 
		28 37 1 29 30 1 29 38 1 30 31 1 
		30 39 1 31 32 1 31 40 1 32 33 1 
		32 41 1 33 34 1 33 42 1 34 35 1 
		34 43 1 35 44 0 36 37 1 36 45 0 
		37 38 1 37 46 1 38 39 1 38 47 1 
		39 40 1 39 48 1 40 41 1 40 49 1 
		41 42 1 41 50 1 42 43 1 42 51 1 
		43 44 1 43 52 1 44 53 0 45 46 1 
		45 54 0 46 47 1 46 55 1 47 48 1 
		47 56 1 48 49 1 48 57 1 49 50 1 
		49 58 1 50 51 1 50 59 1 51 52 1 
		51 60 1 52 53 1 52 61 1 53 62 0 
		54 55 1 54 63 0 55 56 1 55 64 1 
		56 57 1 56 65 1 57 58 1 57 66 1 
		58 59 1 58 67 1 59 60 1 59 68 1 
		60 61 1 60 69 1 61 62 1 61 70 1 
		62 71 0 63 64 1 63 72 0 64 65 1 
		64 73 1 65 66 1 65 74 1 66 67 1 
		66 75 1 67 68 1 67 76 1 68 69 1 
		68 77 1 69 70 1 69 78 1 70 71 1 
		70 79 1 71 80 0 72 73 0 73 74 0 
		74 75 0 75 76 0 76 77 0 77 78 0 
		78 79 0 79 80 0;
	setAttr -s 64 ".fc[0:63]" -type "polyFaces" 
		f 4 0 3 -18 -2 
		mu 0 4 0 1 10 9 
		f 4 2 5 -20 -4 
		mu 0 4 1 2 11 10 
		f 4 4 7 -22 -6 
		mu 0 4 2 3 12 11 
		f 4 6 9 -24 -8 
		mu 0 4 3 4 13 12 
		f 4 8 11 -26 -10 
		mu 0 4 4 5 14 13 
		f 4 10 13 -28 -12 
		mu 0 4 5 6 15 14 
		f 4 12 15 -30 -14 
		mu 0 4 6 7 16 15 
		f 4 14 16 -32 -16 
		mu 0 4 7 8 17 16 
		f 4 17 20 -35 -19 
		mu 0 4 9 10 19 18 
		f 4 19 22 -37 -21 
		mu 0 4 10 11 20 19 
		f 4 21 24 -39 -23 
		mu 0 4 11 12 21 20 
		f 4 23 26 -41 -25 
		mu 0 4 12 13 22 21 
		f 4 25 28 -43 -27 
		mu 0 4 13 14 23 22 
		f 4 27 30 -45 -29 
		mu 0 4 14 15 24 23 
		f 4 29 32 -47 -31 
		mu 0 4 15 16 25 24 
		f 4 31 33 -49 -33 
		mu 0 4 16 17 26 25 
		f 4 34 37 -52 -36 
		mu 0 4 18 19 28 27 
		f 4 36 39 -54 -38 
		mu 0 4 19 20 29 28 
		f 4 38 41 -56 -40 
		mu 0 4 20 21 30 29 
		f 4 40 43 -58 -42 
		mu 0 4 21 22 31 30 
		f 4 42 45 -60 -44 
		mu 0 4 22 23 32 31 
		f 4 44 47 -62 -46 
		mu 0 4 23 24 33 32 
		f 4 46 49 -64 -48 
		mu 0 4 24 25 34 33 
		f 4 48 50 -66 -50 
		mu 0 4 25 26 35 34 
		f 4 51 54 -69 -53 
		mu 0 4 27 28 37 36 
		f 4 53 56 -71 -55 
		mu 0 4 28 29 38 37 
		f 4 55 58 -73 -57 
		mu 0 4 29 30 39 38 
		f 4 57 60 -75 -59 
		mu 0 4 30 31 40 39 
		f 4 59 62 -77 -61 
		mu 0 4 31 32 41 40 
		f 4 61 64 -79 -63 
		mu 0 4 32 33 42 41 
		f 4 63 66 -81 -65 
		mu 0 4 33 34 43 42 
		f 4 65 67 -83 -67 
		mu 0 4 34 35 44 43 
		f 4 68 71 -86 -70 
		mu 0 4 36 37 46 45 
		f 4 70 73 -88 -72 
		mu 0 4 37 38 47 46 
		f 4 72 75 -90 -74 
		mu 0 4 38 39 48 47 
		f 4 74 77 -92 -76 
		mu 0 4 39 40 49 48 
		f 4 76 79 -94 -78 
		mu 0 4 40 41 50 49 
		f 4 78 81 -96 -80 
		mu 0 4 41 42 51 50 
		f 4 80 83 -98 -82 
		mu 0 4 42 43 52 51 
		f 4 82 84 -100 -84 
		mu 0 4 43 44 53 52 
		f 4 85 88 -103 -87 
		mu 0 4 45 46 55 54 
		f 4 87 90 -105 -89 
		mu 0 4 46 47 56 55 
		f 4 89 92 -107 -91 
		mu 0 4 47 48 57 56 
		f 4 91 94 -109 -93 
		mu 0 4 48 49 58 57 
		f 4 93 96 -111 -95 
		mu 0 4 49 50 59 58 
		f 4 95 98 -113 -97 
		mu 0 4 50 51 60 59 
		f 4 97 100 -115 -99 
		mu 0 4 51 52 61 60 
		f 4 99 101 -117 -101 
		mu 0 4 52 53 62 61 
		f 4 102 105 -120 -104 
		mu 0 4 54 55 64 63 
		f 4 104 107 -122 -106 
		mu 0 4 55 56 65 64 
		f 4 106 109 -124 -108 
		mu 0 4 56 57 66 65 
		f 4 108 111 -126 -110 
		mu 0 4 57 58 67 66 
		f 4 110 113 -128 -112 
		mu 0 4 58 59 68 67 
		f 4 112 115 -130 -114 
		mu 0 4 59 60 69 68 
		f 4 114 117 -132 -116 
		mu 0 4 60 61 70 69 
		f 4 116 118 -134 -118 
		mu 0 4 61 62 71 70 
		f 4 119 122 -137 -121 
		mu 0 4 63 64 73 72 
		f 4 121 124 -138 -123 
		mu 0 4 64 65 74 73 
		f 4 123 126 -139 -125 
		mu 0 4 65 66 75 74 
		f 4 125 128 -140 -127 
		mu 0 4 66 67 76 75 
		f 4 127 130 -141 -129 
		mu 0 4 67 68 77 76 
		f 4 129 132 -142 -131 
		mu 0 4 68 69 78 77 
		f 4 131 134 -143 -133 
		mu 0 4 69 70 79 78 
		f 4 133 135 -144 -135 
		mu 0 4 70 71 80 79 ;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
createNode lightLinker -n "lightLinker1";
	setAttr -s 2 ".lnk";
	setAttr -s 2 ".slnk";
createNode displayLayerManager -n "layerManager";
createNode displayLayer -n "defaultLayer";
createNode renderLayerManager -n "renderLayerManager";
createNode renderLayer -n "defaultRenderLayer";
	setAttr ".g" yes;
createNode script -n "uiConfigurationScriptNode";
	setAttr ".b" -type "string" (
		"// Maya Mel UI Configuration File.\n//\n//  This script is machine generated.  Edit at your own risk.\n//\n//\n\nglobal string $gMainPane;\nif (`paneLayout -exists $gMainPane`) {\n\n\tglobal int $gUseScenePanelConfig;\n\tint    $useSceneConfig = $gUseScenePanelConfig;\n\tint    $menusOkayInPanels = `optionVar -q allowMenusInPanels`;\tint    $nVisPanes = `paneLayout -q -nvp $gMainPane`;\n\tint    $nPanes = 0;\n\tstring $editorName;\n\tstring $panelName;\n\tstring $itemFilterName;\n\tstring $panelConfig;\n\n\t//\n\t//  get current state of the UI\n\t//\n\tsceneUIReplacement -update $gMainPane;\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Top View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Top View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"top\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"wireframe\" \n"
		+ "                -activeOnly 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 8192\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -maxConstantTransparency 1\n                -rendererName \"base_OpenGL_Renderer\" \n                -colorResolution 256 256 \n"
		+ "                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n"
		+ "                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -shadows 0\n                $editorName;\nmodelEditor -e -viewSelected 0 $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Top View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"top\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"wireframe\" \n            -activeOnly 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n"
		+ "            -twoSidedLighting 1\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 8192\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -maxConstantTransparency 1\n            -rendererName \"base_OpenGL_Renderer\" \n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n"
		+ "            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -shadows 0\n            $editorName;\nmodelEditor -e -viewSelected 0 $editorName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Side View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Side View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"side\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"wireframe\" \n                -activeOnly 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n"
		+ "                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 8192\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -maxConstantTransparency 1\n                -rendererName \"base_OpenGL_Renderer\" \n                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n"
		+ "                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -shadows 0\n                $editorName;\nmodelEditor -e -viewSelected 0 $editorName;\n"
		+ "\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Side View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"side\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"wireframe\" \n            -activeOnly 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 1\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 8192\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n"
		+ "            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -maxConstantTransparency 1\n            -rendererName \"base_OpenGL_Renderer\" \n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n"
		+ "            -hulls 1\n            -grid 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -shadows 0\n            $editorName;\nmodelEditor -e -viewSelected 0 $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Front View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Front View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"front\" \n                -useInteractiveMode 0\n"
		+ "                -displayLights \"default\" \n                -displayAppearance \"wireframe\" \n                -activeOnly 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 8192\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -maxConstantTransparency 1\n"
		+ "                -rendererName \"base_OpenGL_Renderer\" \n                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n"
		+ "                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -shadows 0\n                $editorName;\nmodelEditor -e -viewSelected 0 $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Front View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"front\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"wireframe\" \n            -activeOnly 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n"
		+ "            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 1\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 8192\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -maxConstantTransparency 1\n            -rendererName \"base_OpenGL_Renderer\" \n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n"
		+ "            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n"
		+ "            -textures 1\n            -strokes 1\n            -shadows 0\n            $editorName;\nmodelEditor -e -viewSelected 0 $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Persp View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"persp\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"wireframe\" \n                -activeOnly 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n"
		+ "                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 8192\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -maxConstantTransparency 1\n                -rendererName \"base_OpenGL_Renderer\" \n                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n"
		+ "                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n"
		+ "                -shadows 0\n                $editorName;\nmodelEditor -e -viewSelected 0 $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"persp\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"wireframe\" \n            -activeOnly 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 1\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 8192\n"
		+ "            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -maxConstantTransparency 1\n            -rendererName \"base_OpenGL_Renderer\" \n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n"
		+ "            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -shadows 0\n            $editorName;\nmodelEditor -e -viewSelected 0 $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"Outliner\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `outlinerPanel -unParent -l (localizedPanelLabel(\"Outliner\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            outlinerEditor -e \n"
		+ "                -showShapes 1\n                -showAttributes 0\n                -showConnected 0\n                -showAnimCurvesOnly 0\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 0\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 1\n                -showPublishedAsConnected 0\n                -showContainerContents 1\n                -ignoreDagHierarchy 0\n                -expandConnections 0\n                -showUnitlessCurves 1\n                -showCompounds 1\n                -showLeafs 1\n                -showNumericAttrsOnly 0\n                -highlightActive 1\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 0\n                -setFilter \"defaultSetFilter\" \n                -showSetMembers 1\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n"
		+ "                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\toutlinerPanel -edit -l (localizedPanelLabel(\"Outliner\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        outlinerEditor -e \n            -showShapes 1\n            -showAttributes 0\n            -showConnected 0\n            -showAnimCurvesOnly 0\n            -showMuteInfo 0\n            -organizeByLayer 1\n            -showAnimLayerWeight 1\n"
		+ "            -autoExpandLayers 1\n            -autoExpand 0\n            -showDagOnly 0\n            -showAssets 1\n            -showContainedOnly 1\n            -showPublishedAsConnected 0\n            -showContainerContents 1\n            -ignoreDagHierarchy 0\n            -expandConnections 0\n            -showUnitlessCurves 1\n            -showCompounds 1\n            -showLeafs 1\n            -showNumericAttrsOnly 0\n            -highlightActive 1\n            -autoSelectNewObjects 0\n            -doNotSelectNewObjects 0\n            -dropIsParent 1\n            -transmitFilters 0\n            -setFilter \"defaultSetFilter\" \n            -showSetMembers 1\n            -allowMultiSelection 1\n            -alwaysToggleSelect 0\n            -directSelect 0\n            -displayMode \"DAG\" \n            -expandObjects 0\n            -setsIgnoreFilters 1\n            -containersIgnoreFilters 0\n            -editAttrName 0\n            -showAttrValues 0\n            -highlightSecondary 0\n            -showUVAttrsOnly 0\n            -showTextureNodesOnly 0\n"
		+ "            -attrAlphaOrder \"default\" \n            -animLayerFilterOptions \"allAffecting\" \n            -sortOrder \"none\" \n            -longNames 0\n            -niceNames 1\n            -showNamespace 1\n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\tif ($useSceneConfig) {\n\t\toutlinerPanel -e -to $panelName;\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"graphEditor\" (localizedPanelLabel(\"Graph Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"graphEditor\" -l (localizedPanelLabel(\"Graph Editor\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 1\n"
		+ "                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUnitlessCurves 1\n                -showCompounds 0\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 1\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 1\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n"
		+ "                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"GraphEd\");\n            animCurveEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 1\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -showResults \"off\" \n                -showBufferCurves \"off\" \n                -smoothness \"fine\" \n                -resultSamples 1\n                -resultScreenSamples 0\n                -resultUpdate \"delayed\" \n                -constrainDrag 0\n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Graph Editor\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 1\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUnitlessCurves 1\n                -showCompounds 0\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 1\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 1\n                -setFilter \"0\" \n                -showSetMembers 0\n"
		+ "                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"GraphEd\");\n            animCurveEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 1\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n"
		+ "                -showResults \"off\" \n                -showBufferCurves \"off\" \n                -smoothness \"fine\" \n                -resultSamples 1\n                -resultScreenSamples 0\n                -resultUpdate \"delayed\" \n                -constrainDrag 0\n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dopeSheetPanel\" (localizedPanelLabel(\"Dope Sheet\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"dopeSheetPanel\" -l (localizedPanelLabel(\"Dope Sheet\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 0\n"
		+ "                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUnitlessCurves 0\n                -showCompounds 1\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 1\n                -dropIsParent 1\n                -transmitFilters 0\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n"
		+ "                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"DopeSheetEd\");\n            dopeSheetEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -outliner \"dopeSheetPanel1OutlineEd\" \n                -showSummary 1\n                -showScene 0\n                -hierarchyBelow 0\n                -showTicks 1\n                -selectionWindow 0 0 0 0 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dope Sheet\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 0\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUnitlessCurves 0\n                -showCompounds 1\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 1\n                -dropIsParent 1\n                -transmitFilters 0\n                -setFilter \"0\" \n                -showSetMembers 0\n"
		+ "                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"DopeSheetEd\");\n            dopeSheetEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n"
		+ "                -outliner \"dopeSheetPanel1OutlineEd\" \n                -showSummary 1\n                -showScene 0\n                -hierarchyBelow 0\n                -showTicks 1\n                -selectionWindow 0 0 0 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"clipEditorPanel\" (localizedPanelLabel(\"Trax Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"clipEditorPanel\" -l (localizedPanelLabel(\"Trax Editor\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = clipEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayKeys 0\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n"
		+ "\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Trax Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = clipEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayKeys 0\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -autoFit 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperGraphPanel\" (localizedPanelLabel(\"Hypergraph Hierarchy\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"hyperGraphPanel\" -l (localizedPanelLabel(\"Hypergraph Hierarchy\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"HyperGraphEd\");\n            hyperGraph -e \n                -graphLayoutStyle \"hierarchicalLayout\" \n                -orientation \"horiz\" \n"
		+ "                -mergeConnections 0\n                -zoom 1\n                -animateTransition 0\n                -showRelationships 1\n                -showShapes 0\n                -showDeformers 0\n                -showExpressions 0\n                -showConstraints 0\n                -showUnderworld 0\n                -showInvisible 0\n                -transitionFrames 1\n                -opaqueContainers 0\n                -freeform 0\n                -imagePosition 0 0 \n                -imageScale 1\n                -imageEnabled 0\n                -graphType \"DAG\" \n                -heatMapDisplay 0\n                -updateSelection 1\n                -updateNodeAdded 1\n                -useDrawOverrideColor 0\n                -limitGraphTraversal -1\n                -range 0 0 \n                -iconSize \"smallIcons\" \n                -showCachedConnections 0\n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypergraph Hierarchy\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\t\t$editorName = ($panelName+\"HyperGraphEd\");\n            hyperGraph -e \n                -graphLayoutStyle \"hierarchicalLayout\" \n                -orientation \"horiz\" \n                -mergeConnections 0\n                -zoom 1\n                -animateTransition 0\n                -showRelationships 1\n                -showShapes 0\n                -showDeformers 0\n                -showExpressions 0\n                -showConstraints 0\n                -showUnderworld 0\n                -showInvisible 0\n                -transitionFrames 1\n                -opaqueContainers 0\n                -freeform 0\n                -imagePosition 0 0 \n                -imageScale 1\n                -imageEnabled 0\n                -graphType \"DAG\" \n                -heatMapDisplay 0\n                -updateSelection 1\n                -updateNodeAdded 1\n                -useDrawOverrideColor 0\n                -limitGraphTraversal -1\n                -range 0 0 \n                -iconSize \"smallIcons\" \n                -showCachedConnections 0\n"
		+ "                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperShadePanel\" (localizedPanelLabel(\"Hypershade\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"hyperShadePanel\" -l (localizedPanelLabel(\"Hypershade\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypershade\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"visorPanel\" (localizedPanelLabel(\"Visor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"visorPanel\" -l (localizedPanelLabel(\"Visor\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Visor\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"polyTexturePlacementPanel\" (localizedPanelLabel(\"UV Texture Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"polyTexturePlacementPanel\" -l (localizedPanelLabel(\"UV Texture Editor\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"UV Texture Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"multiListerPanel\" (localizedPanelLabel(\"Multilister\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"multiListerPanel\" -l (localizedPanelLabel(\"Multilister\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Multilister\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"renderWindowPanel\" (localizedPanelLabel(\"Render View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"renderWindowPanel\" -l (localizedPanelLabel(\"Render View\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Render View\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"blendShapePanel\" (localizedPanelLabel(\"Blend Shape\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\tblendShapePanel -unParent -l (localizedPanelLabel(\"Blend Shape\")) -mbv $menusOkayInPanels ;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tblendShapePanel -edit -l (localizedPanelLabel(\"Blend Shape\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n"
		+ "\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dynRelEdPanel\" (localizedPanelLabel(\"Dynamic Relationships\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"dynRelEdPanel\" -l (localizedPanelLabel(\"Dynamic Relationships\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dynamic Relationships\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"devicePanel\" (localizedPanelLabel(\"Devices\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\tdevicePanel -unParent -l (localizedPanelLabel(\"Devices\")) -mbv $menusOkayInPanels ;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tdevicePanel -edit -l (localizedPanelLabel(\"Devices\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n"
		+ "\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"relationshipPanel\" (localizedPanelLabel(\"Relationship Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"relationshipPanel\" -l (localizedPanelLabel(\"Relationship Editor\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Relationship Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"referenceEditorPanel\" (localizedPanelLabel(\"Reference Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"referenceEditorPanel\" -l (localizedPanelLabel(\"Reference Editor\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Reference Editor\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"componentEditorPanel\" (localizedPanelLabel(\"Component Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"componentEditorPanel\" -l (localizedPanelLabel(\"Component Editor\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Component Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dynPaintScriptedPanelType\" (localizedPanelLabel(\"Paint Effects\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"dynPaintScriptedPanelType\" -l (localizedPanelLabel(\"Paint Effects\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Paint Effects\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"webBrowserPanel\" (localizedPanelLabel(\"Web Browser\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"webBrowserPanel\" -l (localizedPanelLabel(\"Web Browser\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Web Browser\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"scriptEditorPanel\" (localizedPanelLabel(\"Script Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"scriptEditorPanel\" -l (localizedPanelLabel(\"Script Editor\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Script Editor\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\tif ($useSceneConfig) {\n\t\tscriptedPanel -e -to $panelName;\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperGraphPanel\" (localizedPanelLabel(\"Hypergraph InputOutput1\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"hyperGraphPanel\" -l (localizedPanelLabel(\"Hypergraph InputOutput1\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"HyperGraphEd\");\n            hyperGraph -e \n                -graphLayoutStyle \"hierarchicalLayout\" \n                -orientation \"horiz\" \n                -mergeConnections 1\n                -zoom 0.587171\n                -animateTransition 0\n                -showRelationships 1\n                -showShapes 0\n                -showDeformers 0\n                -showExpressions 0\n                -showConstraints 0\n                -showUnderworld 0\n                -showInvisible 0\n                -transitionFrames 5\n                -currentNode \"xxRBF1\" \n"
		+ "                -opaqueContainers 0\n                -freeform 0\n                -imagePosition 0 0 \n                -imageScale 1\n                -imageEnabled 0\n                -graphType \"DG\" \n                -heatMapDisplay 0\n                -updateSelection 1\n                -updateNodeAdded 1\n                -useDrawOverrideColor 0\n                -limitGraphTraversal -1\n                -range 194706190466334860000000000000000000000000000000000000000000000000000000000000000000000000 1528762482635439900000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 \n                -iconSize \"largeIcons\" \n                -showCachedConnections 0\n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypergraph InputOutput1\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"HyperGraphEd\");\n"
		+ "            hyperGraph -e \n                -graphLayoutStyle \"hierarchicalLayout\" \n                -orientation \"horiz\" \n                -mergeConnections 1\n                -zoom 0.587171\n                -animateTransition 0\n                -showRelationships 1\n                -showShapes 0\n                -showDeformers 0\n                -showExpressions 0\n                -showConstraints 0\n                -showUnderworld 0\n                -showInvisible 0\n                -transitionFrames 5\n                -currentNode \"xxRBF1\" \n                -opaqueContainers 0\n                -freeform 0\n                -imagePosition 0 0 \n                -imageScale 1\n                -imageEnabled 0\n                -graphType \"DG\" \n                -heatMapDisplay 0\n                -updateSelection 1\n                -updateNodeAdded 1\n                -useDrawOverrideColor 0\n                -limitGraphTraversal -1\n                -range 194706190466334860000000000000000000000000000000000000000000000000000000000000000000000000 1528762482635439900000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 \n"
		+ "                -iconSize \"largeIcons\" \n                -showCachedConnections 0\n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\tif ($useSceneConfig) {\n\t\tscriptedPanel -e -to $panelName;\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperGraphPanel\" (localizedPanelLabel(\"Hypergraph InputOutput2\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"hyperGraphPanel\" -l (localizedPanelLabel(\"Hypergraph InputOutput2\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"HyperGraphEd\");\n            hyperGraph -e \n                -graphLayoutStyle \"hierarchicalLayout\" \n                -orientation \"horiz\" \n                -mergeConnections 0\n                -zoom 0.43037\n                -animateTransition 0\n                -showRelationships 1\n                -showShapes 0\n                -showDeformers 0\n                -showExpressions 0\n                -showConstraints 0\n                -showUnderworld 0\n"
		+ "                -showInvisible 0\n                -transitionFrames 5\n                -currentEdge \"UnnamedGraphNode\" \n                -opaqueContainers 0\n                -fromAttr \"pPlaneShape3.outMesh\" \n                -toAttr \"xxRBF1.iTargetMesh\" \n                -freeform 0\n                -imagePosition 0 0 \n                -imageScale 1\n                -imageEnabled 0\n                -graphType \"DG\" \n                -heatMapDisplay 0\n                -updateSelection 1\n                -updateNodeAdded 1\n                -useDrawOverrideColor 0\n                -limitGraphTraversal -1\n                -range 0 0 \n                -iconSize \"largeIcons\" \n                -showCachedConnections 0\n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypergraph InputOutput2\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"HyperGraphEd\");\n            hyperGraph -e \n                -graphLayoutStyle \"hierarchicalLayout\" \n"
		+ "                -orientation \"horiz\" \n                -mergeConnections 0\n                -zoom 0.43037\n                -animateTransition 0\n                -showRelationships 1\n                -showShapes 0\n                -showDeformers 0\n                -showExpressions 0\n                -showConstraints 0\n                -showUnderworld 0\n                -showInvisible 0\n                -transitionFrames 5\n                -currentEdge \"UnnamedGraphNode\" \n                -opaqueContainers 0\n                -fromAttr \"pPlaneShape3.outMesh\" \n                -toAttr \"xxRBF1.iTargetMesh\" \n                -freeform 0\n                -imagePosition 0 0 \n                -imageScale 1\n                -imageEnabled 0\n                -graphType \"DG\" \n                -heatMapDisplay 0\n                -updateSelection 1\n                -updateNodeAdded 1\n                -useDrawOverrideColor 0\n                -limitGraphTraversal -1\n                -range 0 0 \n                -iconSize \"largeIcons\" \n                -showCachedConnections 0\n"
		+ "                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\tif ($useSceneConfig) {\n\t\tscriptedPanel -e -to $panelName;\n\t}\n\n\n\tif ($useSceneConfig) {\n        string $configName = `getPanel -cwl (localizedPanelLabel(\"Current Layout\"))`;\n        if (\"\" != $configName) {\n\t\t\tpanelConfiguration -edit -label (localizedPanelLabel(\"Current Layout\")) \n\t\t\t\t-defaultImage \"\"\n\t\t\t\t-image \"\"\n\t\t\t\t-sc false\n\t\t\t\t-configString \"global string $gMainPane; paneLayout -e -cn \\\"quad\\\" -ps 1 50 50 -ps 2 50 50 -ps 3 50 50 -ps 4 50 50 $gMainPane;\"\n\t\t\t\t-removeAllPanels\n\t\t\t\t-ap true\n\t\t\t\t\t(localizedPanelLabel(\"Top View\")) \n\t\t\t\t\t\"modelPanel\"\n"
		+ "\t\t\t\t\t\"$panelName = `modelPanel -unParent -l (localizedPanelLabel(\\\"Top View\\\")) -mbv $menusOkayInPanels `;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera top` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"wireframe\\\" \\n    -activeOnly 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 1\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 0\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 8192\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -maxConstantTransparency 1\\n    -rendererName \\\"base_OpenGL_Renderer\\\" \\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -shadows 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName\"\n"
		+ "\t\t\t\t\t\"modelPanel -edit -l (localizedPanelLabel(\\\"Top View\\\")) -mbv $menusOkayInPanels  $panelName;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera top` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"wireframe\\\" \\n    -activeOnly 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 1\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 0\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 8192\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -maxConstantTransparency 1\\n    -rendererName \\\"base_OpenGL_Renderer\\\" \\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -shadows 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName\"\n"
		+ "\t\t\t\t-ap false\n\t\t\t\t\t(localizedPanelLabel(\"Persp View\")) \n\t\t\t\t\t\"modelPanel\"\n"
		+ "\t\t\t\t\t\"$panelName = `modelPanel -unParent -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels `;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"wireframe\\\" \\n    -activeOnly 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 1\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 0\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 8192\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -maxConstantTransparency 1\\n    -rendererName \\\"base_OpenGL_Renderer\\\" \\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -shadows 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName\"\n"
		+ "\t\t\t\t\t\"modelPanel -edit -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels  $panelName;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"wireframe\\\" \\n    -activeOnly 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 1\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 0\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 8192\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -maxConstantTransparency 1\\n    -rendererName \\\"base_OpenGL_Renderer\\\" \\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -shadows 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName\"\n"
		+ "\t\t\t\t-ap false\n\t\t\t\t\t(localizedPanelLabel(\"Side View\")) \n\t\t\t\t\t\"modelPanel\"\n"
		+ "\t\t\t\t\t\"$panelName = `modelPanel -unParent -l (localizedPanelLabel(\\\"Side View\\\")) -mbv $menusOkayInPanels `;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera side` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"wireframe\\\" \\n    -activeOnly 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 1\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 0\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 8192\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -maxConstantTransparency 1\\n    -rendererName \\\"base_OpenGL_Renderer\\\" \\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -shadows 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName\"\n"
		+ "\t\t\t\t\t\"modelPanel -edit -l (localizedPanelLabel(\\\"Side View\\\")) -mbv $menusOkayInPanels  $panelName;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera side` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"wireframe\\\" \\n    -activeOnly 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 1\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 0\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 8192\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -maxConstantTransparency 1\\n    -rendererName \\\"base_OpenGL_Renderer\\\" \\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -shadows 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName\"\n"
		+ "\t\t\t\t-ap false\n\t\t\t\t\t(localizedPanelLabel(\"Front View\")) \n\t\t\t\t\t\"modelPanel\"\n"
		+ "\t\t\t\t\t\"$panelName = `modelPanel -unParent -l (localizedPanelLabel(\\\"Front View\\\")) -mbv $menusOkayInPanels `;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera front` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"wireframe\\\" \\n    -activeOnly 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 1\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 0\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 8192\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -maxConstantTransparency 1\\n    -rendererName \\\"base_OpenGL_Renderer\\\" \\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -shadows 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName\"\n"
		+ "\t\t\t\t\t\"modelPanel -edit -l (localizedPanelLabel(\\\"Front View\\\")) -mbv $menusOkayInPanels  $panelName;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera front` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"wireframe\\\" \\n    -activeOnly 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 1\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 0\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 8192\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -maxConstantTransparency 1\\n    -rendererName \\\"base_OpenGL_Renderer\\\" \\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -shadows 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName\"\n"
		+ "\t\t\t\t$configName;\n\n            setNamedPanelLayout (localizedPanelLabel(\"Current Layout\"));\n        }\n\n        panelHistory -e -clear mainPanelHistory;\n        setFocus `paneLayout -q -p1 $gMainPane`;\n        sceneUIReplacement -deleteRemaining;\n        sceneUIReplacement -clear;\n\t}\n\n\ngrid -spacing 5 -size 12 -divisions 5 -displayAxes yes -displayGridLines yes -displayDivisionLines yes -displayPerspectiveLabels no -displayOrthographicLabels no -displayAxesBold no -perspectiveLabelPosition axis -orthographicLabelPosition edge;\nviewManip -drawCompass 0 -compassAngle 0 -frontParameters \"\" -homeParameters \"\" -selectionLockParameters \"\";\n}\n");
	setAttr ".st" 3;
createNode script -n "sceneConfigurationScriptNode";
	setAttr ".b" -type "string" "playbackOptions -min 1 -max 24 -ast 1 -aet 48 ";
	setAttr ".st" 6;
createNode xxRBF -n "xxRBF1";
	setAttr -s 4 ".pib[0:3]"  56 20 41 44;
	setAttr -s 4 ".pit[0:3]"  56 20 41 44;
select -ne :time1;
	setAttr ".o" 1;
select -ne :renderPartition;
	setAttr -s 2 ".st";
select -ne :renderGlobalsList1;
select -ne :defaultShaderList1;
	setAttr -s 2 ".s";
select -ne :postProcessList1;
	setAttr -s 2 ".p";
select -ne :lightList1;
select -ne :initialShadingGroup;
	setAttr -s 3 ".dsm";
	setAttr ".ro" yes;
select -ne :initialParticleSE;
	setAttr ".ro" yes;
select -ne :hardwareRenderGlobals;
	setAttr ".ctrs" 256;
	setAttr ".btrs" 512;
select -ne :defaultHardwareRenderGlobals;
	setAttr ".fn" -type "string" "im";
	setAttr ".res" -type "string" "ntsc_4d 646 485 1.333";
connectAttr "xxRBF1.od" "pPlaneShape4.dn";
connectAttr ":defaultLightSet.msg" "lightLinker1.lnk[0].llnk";
connectAttr ":initialShadingGroup.msg" "lightLinker1.lnk[0].olnk";
connectAttr ":defaultLightSet.msg" "lightLinker1.lnk[1].llnk";
connectAttr ":initialParticleSE.msg" "lightLinker1.lnk[1].olnk";
connectAttr ":defaultLightSet.msg" "lightLinker1.slnk[0].sllk";
connectAttr ":initialShadingGroup.msg" "lightLinker1.slnk[0].solk";
connectAttr ":defaultLightSet.msg" "lightLinker1.slnk[1].sllk";
connectAttr ":initialParticleSE.msg" "lightLinker1.slnk[1].solk";
connectAttr "layerManager.dli[0]" "defaultLayer.id";
connectAttr "renderLayerManager.rlmi[0]" "defaultRenderLayer.rlid";
connectAttr "pPlaneShape2.o" "xxRBF1.ibm";
connectAttr "pPlaneShape3.o" "xxRBF1.itm";
connectAttr "lightLinker1.msg" ":lightList1.ln" -na;
connectAttr "pPlaneShape2.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pPlaneShape3.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pPlaneShape4.iog" ":initialShadingGroup.dsm" -na;
// End of rbf_plane_rbfnode_connected.ma
