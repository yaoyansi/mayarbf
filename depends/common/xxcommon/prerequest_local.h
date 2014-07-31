#ifndef _PREREQUEST_LOCAL_H_
#define _PREREQUEST_LOCAL_H_

#include "xxcommon/typedefine.h"
#include "xxcommon/log.h"
#include "xxcommon/util.h"
#include "xxcommon/PluginManager.h"



#define SAFE_DELETE(p)	\
{					\
	if(p!=NULL){	\
	delete p;	\
	p = NULL;	\
	}				\
}

#endif//_PREREQUEST_LOCAL_H_
