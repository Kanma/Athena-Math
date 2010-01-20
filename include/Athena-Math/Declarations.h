/**	@file	Declarations.h
	@author	Philip Abbet

	Declare all the macros needed by the Athena-Math module
*/

#ifndef _ATHENA_MATH_DECLARATIONS_H_
#define _ATHENA_MATH_DECLARATIONS_H_

#include <Athena-Math/Config.h>

// Supported platforms
#define ATHENA_PLATFORM_WIN32 1
#define ATHENA_PLATFORM_LINUX 2
#define ATHENA_PLATFORM_APPLE 3

// Supported compilers
#define ATHENA_COMPILER_MSVC 1
#define ATHENA_COMPILER_GNUC 2

// Endianess
#define ATHENA_ENDIAN_LITTLE 1
#define ATHENA_ENDIAN_BIG 2

// Supported architectures
#define ATHENA_ARCHITECTURE_32 1
#define ATHENA_ARCHITECTURE_64 2

// Finds the compiler type and version
#if defined( _MSC_VER )
#   define ATHENA_COMPILER ATHENA_COMPILER_MSVC
#   define ATHENA_COMP_VER _MSC_VER
#elif defined( __GNUC__ )
#   define ATHENA_COMPILER ATHENA_COMPILER_GNUC
#   define ATHENA_COMP_VER (((__GNUC__)*100) + \
        (__GNUC_MINOR__*10) + \
        __GNUC_PATCHLEVEL__)
#else
#   pragma error "No known compiler"
#endif

// Finds the current platform
#if defined( __WIN32__ ) || defined( _WIN32 )
#   define ATHENA_PLATFORM ATHENA_PLATFORM_WIN32
#elif defined( __APPLE_CC__)
#   define ATHENA_PLATFORM ATHENA_PLATFORM_APPLE
#else
#   define ATHENA_PLATFORM ATHENA_PLATFORM_LINUX
#endif

// Finds the architecture type
#if defined(__x86_64__) || defined(_M_X64) || defined(__powerpc64__) || defined(__alpha__) || defined(__ia64__) || defined(__s390__) || defined(__s390x__)
#   define ATHENA_ARCH_TYPE ATHENA_ARCHITECTURE_64
#else
#   define ATHENA_ARCH_TYPE ATHENA_ARCHITECTURE_32
#endif

/// Used to export symbols from the library
#if ATHENA_PLATFORM == ATHENA_PLATFORM_WIN32
#	ifdef ATHENA_EXPORTS
#		define ATHENA_SYMBOL	__declspec(dllexport)
#	else
#		define ATHENA_SYMBOL	__declspec(dllimport)
#	endif
#else
#	define ATHENA_SYMBOL
#endif

/// See if we can use __forceinline or if we need to use __inline instead
#if ATHENA_COMPILER == ATHENA_COMPILER_MSVC
#   if ATHENA_COMP_VER >= 1200
#       define ATHENA_FORCEINLINE __forceinline
#   endif
#else
#   define ATHENA_FORCEINLINE __inline
#endif

// Endian Settings
#ifdef ATHENA_MATH_CONFIG_BIG_ENDIAN
#    define ATHENA_ENDIAN ATHENA_ENDIAN_BIG
#else
#    define ATHENA_ENDIAN ATHENA_ENDIAN_LITTLE
#endif

#endif
