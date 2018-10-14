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
	#include <linux/limits.h>
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
            char* buff = winc_malloc(strlen(pw->pw_dir) + 1);
            strcpy(buff, pw->pw_dir);
            return buff;
        }
		else 
		{
			return NULL;
		}
    }

    char* get_current_directory()
    {
        char* buff = winc_malloc(PATH_MAX);
        if (getcwd(buff, PATH_MAX))
            return buff;
		else 
			return NULL;
    }

#elif defined(_WIN32) || defined(WIN32)

    #include <Windows.h>
	#include <Shlobj.h>

    bool is_directory(const char* path)
    {
		DWORD attribute = GetFileAttributes(path);
		return attribute == FILE_ATTRIBUTE_DIRECTORY;
    }

    bool is_file(const char* path)
    {
		DWORD attribute = GetFileAttributes(path);
		return ( (attribute != INVALID_FILE_ATTRIBUTES) &&
			     (attribute != FILE_ATTRIBUTE_DIRECTORY) );
    }

    char* get_user_directory()
    {	
		WCHAR unicode_buff[MAX_PATH];
		if (SUCCEEDED(SHGetFolderPathW(NULL, CSIDL_PROFILE, NULL, 0, unicode_buff)))
		{
			CHAR* ansi_buff = winc_malloc(MAX_PATH);
			wcstombs(ansi_buff, unicode_buff, MAX_PATH);
			return ansi_buff;
		} 
		else
		{
			return NULL;
		}
    }

    char* get_current_directory()
    {
		CHAR* buff = winc_malloc(MAX_PATH);
		GetCurrentDirectory(MAX_PATH, buff);
		return buff;
	}

#endif // __unix__ and WIN32
