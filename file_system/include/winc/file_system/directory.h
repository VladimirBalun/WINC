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

The file provides the following features:
- Creating new directory;
- Deleting directory; 
- Checking if the directory exists or not.
- Renaming directory.
 */
#ifndef WINC_FILE_SYSTEM_DIRECTORY_H
#define WINC_FILE_SYSTEM_DIRECTORY_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdio.h>

#include "path.h"
#include "winc/utils/typedef.h"

/*!
The function creates a new directory. If the directory 
already exists, then it will not be created and a function will return false.
\param[in] dir_name New directory name for creating.
\return Whether a directory has been created or not.
*/
bool create_dir(const char* dir_name);

/*!
The function removes directory. If the directory doesn't 
exist, then it will not be removed and a function will return false.
\param[in] dir_name Name directory for deleting.
\return Whether a directory has been deleted or not.
*/
bool remove_dir(const char* dir_name);

/*!
The function checks if the directory exists or not.
\param[in] dir_name Name directory for checking.
\return Whether a directory exists or not.
*/
bool is_exist_dir(const char* dir_name);

/*!
The function renames directory.
\param[in] old_dir_name Old name directory for renaming.
\param[in] new_dir_name New name directory after renaming.
\return Whether a directory has been renamed or not.
*/
bool rename_dir(const char* old_dir_name, const char* new_dir_name);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // WINC_FILE_SYSTEM_DIRECTORY_H
