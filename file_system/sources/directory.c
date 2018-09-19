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

#include "winc/file_system/directory.h"

#ifdef __unix__

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>

    bool create_dir(const char* dir_name)
    {
        if (!is_exist_dir(dir_name))
            return mkdir(dir_name, 0777) == 0;
        else
            return false;
    }

    bool remove_dir(const char* dir_name)
    {
        if (is_exist_dir(dir_name))
            return rmdir(dir_name) == 0;
        else
            return false;
    }

    bool is_exist_dir(const char* dir_name)
    {
        struct stat st = { 0 };
        return stat(dir_name, &st) == 0;
    }

    bool rename_dir(const char* old_dir_name, const char* new_dir_name)
    {
        // Soon...
    }

#elif defined(_WIN32) || defined(WIN32)

    #include <Windows.h>

    bool create_dir(const char* dir_name)
    {
        // Soon...
    }

    bool remove_dir(const char* dir_name)
    {
        // Soon...
    }

    bool is_exist_dir(const char* dir_name)
    {
        // Soon...
    }

    bool rename_dir(const char* old_dir_name, const char* new_dir_name)
    {
        // Soon...
    }

#endif // __unix__ and WIN32
