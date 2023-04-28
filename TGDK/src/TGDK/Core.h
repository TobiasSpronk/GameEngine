#pragma once
#include "tgdk_pch.h"

#ifdef TGDK_PLATFORM_WINDOWS
	#ifdef TGDK_BUILD_DLL
		#define TGDK_API __declspec(dllexport)
	#else
		#define TGDK_API __declspec(dllimport)
	#endif
#else
	#error TGDK only supports windows!
#endif

#ifdef TGDK_ENABLE_ASSERTS
	#define TGDK_ASSERT(x, ...) { if(!(x)) { TGDK_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define TGDK_CORE_ASSERT(x, ...) { if(!(x)) { TGDK_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define TGDK_ASSERT(x, ...)
	#define TGDK_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << (x))

#define TGDK_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)