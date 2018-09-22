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

#include "winc/file_system/path.h"

#ifdef __unix__

    #include <unistd.h>
    #include <dirent.h>
    #include <libgen.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <pwd.h>

    bool is_directory(const char* path)
    {
        struct stat buff;
        stat(path, &buff);
        return S_ISDIR(buff.st_mode);
    }

    bool is_file(const char* path)
    {
        struct stat buff;
        stat(path, &buff);
        return S_ISREG(buff.st_mode);
    }

    char* get_user_directory()
    {
        struct passwd* pw = getpwuid(getuid());
        if (pw->pw_dir)
        {
            char* buff = MALLOC(strlen(pw->pw_dir) + 1);
            strcpy(buff, pw->pw_dir);
            return buff;
        }

        return NULL;
    }

    char* get_current_directory()
    {
        static __uint8_t MAX_LENGTH_DIRECTORY = 255;
        char* buff = MALLOC(sizeof(char) * MAX_LENGTH_DIRECTORY);
        if (getcwd(buff, MAX_LENGTH_DIRECTORY))
            return buff;

        return NULL;
    }

    char* get_file_name_from_path(char *path)
    {
        return basename(path);
    }

    void path_iterate(const char* path, void(*func)(const char*))
    {
        DIR *dir;
        struct dirent *ent;
        if ((dir = opendir(path)) != NULL)
        {
            while ((ent = readdir(dir)) != NULL)
            {
                if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0)
                    func(ent->d_name);
            }
            closedir(dir);
        }
    }

#elif defined(_WIN32) || defined(WIN32)

    #include <Windows.h>

    bool is_directory(const char* name)
    {
        // Soon...
    }

    bool is_file(const char* name)
    {
        // Soon...
    }

    const char* get_user_directory()
    {
        // Soon...
    }

    const char* get_current_directory()
    {
        // Soon...
    }

    char* get_file_name_from_path(const char* path)
    {
        // Soon...
    }

    void path_iterate(const char* path, void(*func)(const char*))
    {
        // Soon...
    }

#endif // __unix__ and WIN32
