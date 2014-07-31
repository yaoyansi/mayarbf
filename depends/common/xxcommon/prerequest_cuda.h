#ifndef _PREREQUEST_CUDA_H_
#define _PREREQUEST_CUDA_H_

namespace _mycuda_
{
#include <cuda_runtime.h>
#include <cutil_inline.h>
#include <cutil_gl_inline.h>

#include <cuda_gl_interop.h>
#include <vector_types.h>
}
using namespace _mycuda_;
//#include <cutil_gl_error.h>

#pragma comment(lib,"cudart.lib")

#ifdef _WIN64
#pragma comment(lib,"cutil64.lib")
#else
#pragma comment(lib,"cutil32.lib")
#endif


#endif//_PREREQUEST_CUDA_H_