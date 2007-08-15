/*
 * Copyright 2006-2007 Andrew De Ponte
 *
 * This file is part of lib_gnut.
 *
 * lib_gnut is the intellectual property of Andrew De Ponte; any
 * distribution and/or modification and/or reproductions of any portion
 * of lib_gnut MUST be approved by Andrew De Ponte.
 *
 * lib_gnut is distributed WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.
 */

/**
 * @file gnut_export.h
 * @brief This is a specifications file for Win32 DLL handling.
 *
 * The gnut_export.h file is a specifications that defines the necessary
 * macros for handling the complexities of Win32 DLL creation and
 * linking necessary for the lib_gnut code base.
 */

#ifndef GNUT_EXPORT_H
#define GNUT_EXPORT_H

/* Basically, the autotools (autoconf, automake, and libtool) build
 * tools detect when a Win32 DLL is being built and define the
 * DLL_EXPORT macro. If DLL_EXPORT is defined then we know that it is
 * building a Win32 DLL so we need to use __declspec(dllexport) for each
 * item we would like exposed to the client applications from the DLL.
 * Hence, I have created my own macro GNUT_EXPORT containing this
 * value.
 *
 * If DLL_EXPORT is NOT defined I know that I am NOT building a Win32
 * DLL which leaves me a couple possibilities. One, is that I am
 * building Unix/Linux version of the library, another possibility is
 * that a Unix/Linux client application is linking to the Unix/Linux
 * version of the library. The final possability is that a Win32 client
 * application is linking to the Win32 DLL version of the library. In
 * this last case __declspec(dllimport) must be used for each item that
 * the client application should be allowed to import from the DLL.
 * Hence, we force the user to define a macro (LIBGNUT_DLL_IMPORT)
 * when building/linking a Win32 client application. This tells the
 * library to set the GNUT_EXPORT macro to __declspec(dllimport)
 * rather than __declspec(dllexport).
 *
 * In the cases that one is either building a Unix/Linux client
 * application which links to this library, or building a Unix/Linux
 * version of this library there is no need for doing
 * __declspec(dllexport) or __declspec(dllimport). Hence our
 * GNUT_EXPORT is set to a value of nothing.
 */
#ifdef DLL_EXPORT
    #define GNUT_EXPORT __declspec(dllexport)
#else
    #ifdef LIBGNUT_DLL_IMPORT
        #define GNUT_EXPORT __declspec(dllimport)
    #endif
#endif
#ifndef GNUT_EXPORT
    #define GNUT_EXPORT
#endif

#endif /* GNUT_EXPORT_H */
