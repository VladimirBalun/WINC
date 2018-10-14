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
 \file directory.h
 \authors VladimirBalun
 \brief File for working with directories.
 */
#ifndef WINC_FILE_SYSTEM_DIRECTORY_H
#define WINC_FILE_SYSTEM_DIRECTORY_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdio.h>

#include "winc/file_system/path.h"
#include "winc/utils/typedef.h"

/*!
The function creates a new directory(does not work with files). 
If the directory already exists, then it will not be rereated.
\param[in] dir_name New directory name for creating.
\return If the directory was created, shall return `true`, otherwise `false`.
*/
bool create_dir(const char* dir_name);

/*!
The function removes directory(does not work with files). If 
the directory doesn't exist, then function does nothing
\param[in] dir_name Name directory for deleting.
\return If the directory was deleted, shall return `true`, otherwise `false`.
*/
bool remove_dir(const char* dir_name);

/*!
The function checks if the directory 
exists or not(does not work with files).
\param[in] dir_name Name directory for checking.
\return If the directory exists, shall return `true`, otherwise `false`.
*/
bool is_exist_dir(const char* dir_name);

/*!
The function renames directory(does not work with files). If 
the old name of the directory does not exist or new name of 
the direcory already exists, then function does nothing.
\param[in] old_dir_name Old name directory for renaming.
\param[in] new_dir_name New name directory after renaming.
\return If the directory was renamed, shall return `true`, otherwise `false`.
*/
bool rename_dir(const char* old_dir_name, const char* new_dir_name);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // WINC_FILE_SYSTEM_DIRECTORY_H
