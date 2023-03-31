#pragma once

#ifdef TGDK_PLATFORM_WINDOWS
	#ifdef TGDK_BUILD_DLL
		#define TGDK_API __declspec(dllexport)
	#else
		#define TGDK_API __declspec(dllimport)
	#endif
#else
	#error TGDK only supports windows!
#endif