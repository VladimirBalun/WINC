/*
 * Copyright 2018 Vladimir Balun
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WINC_UTILS_DEBUG_H
#define WINC_UTILS_DEBUG_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#if defined(_DEBUG)

    #include <stdio.h>

	#include "typedef.h"

    #define DEBUG_MSG(text) \
        ( printf("[DEBUG] [%s] [%s:%d] - %s\n", __TIMESTAMP__, __FILE__, __LINE__, (char*)(text)) )

    #define WARN_MSG(text) \
        ( printf("[WARNING] [%s] [%s:%d] - %s\n", __TIMESTAMP__, __FILE__, __LINE__, (char*)(text)) )

    #define ERROR_MSG(text) \
        ( fprintf(stderr, "[ERROR] [%s] [%s:%d] - %s\n", __TIMESTAMP__, __FILE__, __LINE__, (char*)(text)) )

    #define SYSTEM_MSG(text) \
        ( fprintf(stderr, "[SYSTEM] [%s] [%s:%d] - %s\n", __TIMESTAMP__, __FILE__, __LINE__, (char*)(text)) )

    #define ASSERT_MSG(text) \
        ( fprintf(stderr, "[ASSERT] [%s] [%s:%d] - %s\n", __TIMESTAMP__, __FILE__, __LINE__, (char*)(text)) )

    #define ASSERT(expression) \
        if (!(expression)) \
        { \
            ASSERT_MSG("Assertion failed."); \
            exit(ASSERT_FAILED); \
        }

	#ifdef __unix__ 

		#define PRINT_LAST_SYSTEM_ERROR() \
			LPSTR message_buffer = NULL; \
			size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, \
									     NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&message_buffer, 0, NULL);	\
			SYSTEM_MSG(message_buffer);	\
			LocalFree(message_buffer); 

	#elif defined (_WIN32) || (WIN32)

		// Soon will be added...
		#define PRINT_LAST_SYSTEM_ERROR(text) \
			( (void)0 ) 

	#endif // __unix__ and _WIN32

#else

    #define DEBUG_MSG(text) \
        ( (void)0 )

    #define WARN_MSG(text) \
        ( (void)0 )

    #define ERROR_MSG(text) \
        ( (void)0 )

    #define SYSTEM_MSG(text) \
        ( (void)0 )

    #define ASSERT_MSG(text) \
        ( (void)0 )

	#define ASSERT(expression) \
        ( (void)0 )

	#define PRINT_LAST_SYSTEM_ERROR(expression) \
        ( (void)0 )

#endif // DEBUG

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // WINC_UTILS_DEBUG_H
