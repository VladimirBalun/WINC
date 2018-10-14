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

 /*!
 \file path.h
 \authors VladimirBalun
 \brief File for working with path of the file system.
 */
#ifndef WINC_FILE_SYSTEM_PATH_H
#define WINC_FILE_SYSTEM_PATH_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdlib.h>
#include <string.h>

#include "winc/utils/allocation.h"
#include "winc/utils/typedef.h"

/*!
The function checks if the path is directory or not.
If directory is not exist, then a function will return `false`.
\param[in] path Path of the file system.
\return If the path is directory, shall return `true`, 
otherwise `false`.
*/
bool is_directory(const char* path);

/*!
The function checks if the path is file or not.
If file is not exist, then a function will return `false`.
\param[in] path Path of the file system.
\return If the path is file, shall return `true`,
*/
bool is_file(const char* path);

/*!
The function returns the user's home directory.
\warning Memory for path is not released, you will need to release it yourself.
\return Upon successful completion, function shall return the user's 
home directory, otherwise `NULL`.
*/
char* get_user_directory();

/*!
The function returns the current working directory.
\warning Memory for path is not released, you will need to release it yourself.
\return Upon successful completion, function shall return the current 
working directory, otherwise `NULL`.
*/
char* get_current_directory();

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // WINC_FILE_SYSTEM_PATH_H
