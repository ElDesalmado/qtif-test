#pragma once

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#	ifdef BUILD_DLL
#		define DLL_API __declspec(dllexport)
#	else
#		define DLL_API __declspec(dllimport)
#	endif
#else
# 	define DLL_API
#endif

extern "C" DLL_API bool get_version(char *buffer, unsigned int size);