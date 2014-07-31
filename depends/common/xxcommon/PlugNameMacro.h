
/*---------------------------------------------------------------------------------------------

File		:	PlugNameMacro.h
Inputs		:	
Outputs		:	
Description	:	macros for define variables with special format
Comments	:	
History		:	

---------------------------------------------------------------------------------------------*/
#ifndef _PLUG_NAME_MACRO_
#define _PLUG_NAME_MACRO_

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <xxcommon/mayacheck.h>
#include <xxcommon/log.h>

/*---------------------------------------------------------------------------------------------

Macro		:	Plug name declare/implement
Inputs		:	
Outputs		:	
Description	:	* for plug name *
Comments	:	
History		:	

---------------------------------------------------------------------------------------------*/
#define PLUGNAME_DECLARE( LONG_NAME_, SHORT_NAME_ ) static const char* LONG_NAME_; \
													static const char* SHORT_NAME_;

#define PLUGNAME_IMPLEMENT( CLASS_, LONG_NAME_, SHORT_NAME_ )	const char* CLASS_::LONG_NAME_ = #LONG_NAME_; \
																const char* CLASS_::SHORT_NAME_ = #SHORT_NAME_;

/*---------------------------------------------------------------------------------------------

Macro		:	macros 
Inputs		:	
Outputs		:	
Description	:	* for cmd parameters *
Comments	:	
History		:	

---------------------------------------------------------------------------------------------*/
#define FLAG(SEMANTIC)			BOOST_PP_CAT(f, SEMANTIC)
#define SHORTNAME(SEMANTIC)		BOOST_PP_CAT(k, BOOST_PP_CAT(SEMANTIC, _S))
#define LONGNAME(SEMANTIC)		BOOST_PP_CAT(k, BOOST_PP_CAT(SEMANTIC, _L))
#define VARIABLE(SEMANTIC, i)	BOOST_PP_CAT(v, BOOST_PP_CAT(SEMANTIC, i))

/*---------------------------------------------------------------------------------------------
MICRO		:	CMDARG( SEMANTIC, short name, long name )
Example		:	CMDARG( RESOLUTION,  res, resolution ) 
				is expand to:
				static const char * kRESOLUTION_S	= "-res";
				static const char * kRESOLUTION_L	= "-resolution";
---------------------------------------------------------------------------------------------*/
#define IMPLEMENT_PARAM( SEMANTIC, SHORT_NAME_, LONG_NAME_ ) \
	static const char * SHORTNAME(SEMANTIC)	= BOOST_PP_STRINGIZE(BOOST_PP_CAT(-,SHORT_NAME_));\
	static const char * LONGNAME(SEMANTIC)	= BOOST_PP_STRINGIZE(BOOST_PP_CAT(-,LONG_NAME_));

// #define IMPLEMENT_PARAM( SEMANTIC, SHORT_NAME_, LONG_NAME_ ) \
// 	#define SHORTNAME(SEMANTIC)	BOOST_PP_STRINGIZE(BOOST_PP_CAT(-,SHORT_NAME_));\
// 	#define LONGNAME(SEMANTIC)	BOOST_PP_STRINGIZE(BOOST_PP_CAT(-,LONG_NAME_));

/*---------------------------------------------------------------------------------------------
MICRO		:	ADD_PARAM*( SEMANTIC, type of variable 0,  type of variable 1, ... )
Example		:	ADD_PARAM2( RESOLUTION,  size_t, size_t ) 
				is expand to:
				bool fRESOLUTION;
				size_t vRESOLUTION0;
				size_t vRESOLUTION1;
---------------------------------------------------------------------------------------------*/
#define DECLARE_PARAM0( SEMANTIC )\
	bool FLAG( SEMANTIC );

#define DECLARE_PARAM1( SEMANTIC, V_TYPE0 )\
	bool FLAG( SEMANTIC ); \
	V_TYPE0  VARIABLE( SEMANTIC, 0);

#define DECLARE_PARAM2( SEMANTIC, V_TYPE0, V_TYPE1 )\
	bool FLAG( SEMANTIC ); \
	V_TYPE0  VARIABLE( SEMANTIC, 0); \
	V_TYPE1  VARIABLE( SEMANTIC, 1);

/*---------------------------------------------------------------------------------------------
MICRO		:	ADD_ARG*( SEMANTIC, type of variable 0,  type of variable 1, ... )
Example		:	ADD_ARG2( RESOLUTION,  MSyntax::kUnsigned, MSyntax::kUnsigned )
				is expand to:
				IfMErrorWarn(syntax.addFlag( kRESOLUTION_S, kRESOLUTION_L,
				MSyntax::kUnsigned, MSyntax::kUnsigned));
---------------------------------------------------------------------------------------------*/
#define ADD_ARG0( SEMANTIC ) \
	IfMErrorWarn(syntax.addFlag( SHORTNAME(SEMANTIC), LONGNAME(SEMANTIC) ));

#define ADD_ARG1( SEMANTIC, TYPE0_) \
	IfMErrorWarn(syntax.addFlag( SHORTNAME(SEMANTIC), LONGNAME(SEMANTIC), TYPE0_));

#define ADD_ARG2( SEMANTIC, TYPE0_, TYPE1_ ) \
	IfMErrorWarn(syntax.addFlag( SHORTNAME(SEMANTIC), LONGNAME(SEMANTIC), TYPE0_, TYPE1_));

/*---------------------------------------------------------------------------------------------
MICRO		:	GET_ARG*( SEMANTIC )
Example		:	GET_ARG2( RESOLUTION )
				is expand to:
				fRESOLUTION = argData.isFlagSet( LONGNAME(SEMANTIC), &status );
				IfMErrorWarn(status);
				if( fRESOLUTION ){
					argData.getFlagArgument(kRESOLUTION_L, 0, vRESOLUTION0);
					argData.getFlagArgument(kRESOLUTION_L, 1, vRESOLUTION1);
				}else{
					_LogDebug( "RESOLUTION" <<" not set.");
				}
---------------------------------------------------------------------------------------------*/
#define GET_ARG0( SEMANTIC ) \
	FLAG(SEMANTIC) = argData.isFlagSet( LONGNAME(SEMANTIC), &status );

#define GET_ARG1( SEMANTIC ) \
	FLAG(SEMANTIC) = argData.isFlagSet( LONGNAME(SEMANTIC), &status );\
	IfMErrorWarn(status);\
	if( FLAG(SEMANTIC) ){\
		unsigned int a0value = 0;\
		argData.getFlagArgument(LONGNAME(SEMANTIC), a0value, VARIABLE(SEMANTIC,0));\
	}else{\
		_LogDebug( #SEMANTIC <<" not set.");\
	}

#define GET_ARG2( SEMANTIC ) \
	FLAG(SEMANTIC) = argData.isFlagSet( LONGNAME(SEMANTIC), &status );\
	IfMErrorWarn(status);\
	if( FLAG(SEMANTIC) ){\
		argData.getFlagArgument(LONGNAME(SEMANTIC), 0, VARIABLE(SEMANTIC,0));\
		argData.getFlagArgument(LONGNAME(SEMANTIC), 1, VARIABLE(SEMANTIC,1));\
	}else{\
		_LogDebug( #SEMANTIC <<" not set.");\
	}
#define GET_ARG_STRINGARRAY( SEMANTIC ) \
	FLAG(SEMANTIC) = argData.isFlagSet( LONGNAME(SEMANTIC), &status );\
	IfMErrorWarn(status);\
	if( FLAG(SEMANTIC) ){\
		MSelectionList tmp;\
		argData.getFlagArgument(LONGNAME(SEMANTIC), 0, tmp);\
		tmp.getSelectionStrings( VARIABLE(SEMANTIC,0) );\
	}else{\
		_LogDebug( #SEMANTIC <<" not set.");\
	}

#define GETv2_FOR_LOOP_BEGIN( ARGLIST )\
	for (unsigned int i = 0; i < ARGLIST.length(); i++ )\
	{\
		MString param(args.asString( i, &status ));\
		IfMErrorWarn(status);

#define GETv2_FOR_LOOP_END()\
	}

#define GETv2_ARG1( SEMANTIC ) \
	if ((MString(SHORTNAME(SEMANTIC))==param)\
      ||(MString(LONGNAME(SEMANTIC))==param))\
	{\
		unsigned int a0value = i+1;\
		IfMErrorWarn( args.get( a0value, VARIABLE( SEMANTIC, 0) ) );\
		i+=1;\
	}

#define GETv2_ARG2( SEMANTIC ) \
	if ((MString(SHORTNAME(SEMANTIC))==param)\
	  ||(MString(LONGNAME(SEMANTIC))==param))\
	{\
		unsigned int a0value = i+1;\
		unsigned int a1value = i+2;\
		IfMErrorWarn( args.get( a0value, VARIABLE( SEMANTIC, 0) ) );\
		IfMErrorWarn( args.get( a1value, VARIABLE( SEMANTIC, 1) ) );\
		i+=2;\
	}
/*---------------------------------------------------------------------------------------------
MICRO		:	PRINT_ARG*( SEMANTIC )
---------------------------------------------------------------------------------------------*/
#define PRINT_ARG0( SEMANTIC )\
	_LogDebug( #SEMANTIC <<": flag: "<< FLAG(SEMANTIC) );

#define PRINT_ARG1( SEMANTIC )\
	_LogDebug( #SEMANTIC <<": flag: "<< FLAG(SEMANTIC) <<"\tvalue: "<<VARIABLE(SEMANTIC,0) );

#define PRINT_ARG2( SEMANTIC )\
	_LogDebug( #SEMANTIC <<": flag: "<< FLAG(SEMANTIC) <<"\tvalue: "<<VARIABLE(SEMANTIC,0)<<","<<VARIABLE(SEMANTIC,1) );

#endif