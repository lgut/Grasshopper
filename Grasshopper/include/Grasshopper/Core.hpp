#pragma once

// clang-format off
#ifdef GH_PLATFORM_WINDOWS
	#ifdef GH_BUILD_DLL
		#define GRASSHOPPER_API __declspec(dllexport)
	#else
		#define GRASSHOPPER_API __declspec(dllimport)
	#endif

	//TODO: add linux stuff
#elif defined(GH_PLATFORM_LINUX)
	#ifdef GH_BUILD_SO
		#define GRASSHOPPER_API __attribute__((visibility("default")))
	#else
		// gcc has no dllimport equivalent
		#define GRASSHOPPER_API
	#endif
#else
	#define GRASSHOPPER_API
	#pragma warning Platform not supported
#endif