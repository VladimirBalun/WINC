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

#include "winc/file_sytem/file.h"

#if defined(_WIN32) || defined(WIN32)
	#pragma warning(disable:4996)
#endif

bool rename_file(const char* old_file_name, const char* new_file_name)
{
    return rename(old_file_name, new_file_name) == 0;
}

char* read_file(const char* file_name)
{
    FILE *file = fopen(file_name, "r");
    if (!file)
        return NULL;

    long int size = get_file_size(file_name);
    char* data = MALLOC(sizeof(char) * (size_t)(size + 1));
    fread(data, 1, (size_t)size, file);
    data[size] = '\0';
    fclose(file);
    return data;
}

void rewrite_file(const char* file_name, const char* data)
{
    FILE* file = fopen(file_name, "w");
    if (file)
    {
        fprintf(file, "%s", data);
        fclose(file);
    }
}

void append_to_file(const char* file_name, const char* data)
{
    FILE* file = fopen(file_name, "a");
    if (file)
    {
        fprintf(file, "%s", data);
        fclose(file);
    }
}

#ifdef __unix__

	#include <pwd.h>
	#include <fcntl.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <sys/sendfile.h>
	#include <unistd.h>

	bool create_file(const char* full_file_name)
	{
		return creat(full_file_name, S_IRUSR | S_IWUSR) != -1;
	}

	bool copy_file(const char* from_file_name, const char* to_file_name)
	{
		int from_file, to_file;
		if ((from_file = open(from_file_name, O_RDONLY)) == -1)
		    return false;
		if ((to_file = creat(to_file_name, 0660)) == -1)
		{
		    close(from_file);
		    return false;
		}

		off_t bytesCopied = 0;
		struct stat fileinfo = {0};
		fstat(from_file, &fileinfo);
		ssize_t result = sendfile(to_file, from_file, &bytesCopied, (size_t) fileinfo.st_size);

		close(from_file);
		close(to_file);

		return result != -1;
	}

	bool move_file(const char* file_name, const char* new_file_name)
	{
		return rename(file_name, new_file_name) == 0;
	}

	bool create_sym_link(const char *file_name, const char *link_name)
	{
		return symlink(file_name, link_name) == 0;
	}

	bool create_hard_link(const char *file_name, const char *link_name)
	{
		return link(file_name, link_name) == 0;
	}

	long int get_file_size(const char* file_name)
	{
		struct stat st;
		if (stat(file_name, &st) == 0)
		    return st.st_size;
		else
		    return -1;
	}

	bool remove_file(const char* file_name)
	{
		return remove(file_name) == 0;
	}

#endif // __unix__

#if defined(_WIN32) || defined(WIN32)

	#include <Windows.h>

	bool create_file(const char* file_name)
	{
		return CreateFile(file_name, GENERIC_READ | GENERIC_WRITE, NULL, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL) !=  INVALID_HANDLE_VALUE;
	}

	bool copy_file(const char* from_file_name, const char* to_file_name)
	{
		return CopyFile(from_file_name, to_file_name, FALSE) != 0;
	}

	bool move_file(const char* file_name, const char* new_file_name) 
	{
		return MoveFile(file_name, new_file_name) != 0;
	}

	bool remove_file(const char* file_name)
	{
		return DeleteFile(file_name) != 0;
	}

	bool create_sym_link(const char *file_name, const char *link_name)
	{
        return CreateSymbolicLink(link_name, file_name, NULL) != 0;
	}

	bool create_hard_link(const char *file_name, const char *link_name)
	{
		return CreateHardLink(link_name, file_name, NULL) != 0;
	}

	long int get_file_size(const char* file_name)
	{
		WIN32_FILE_ATTRIBUTE_DATA fattr;
		if (!GetFileAttributesEx(file_name, GetFileExInfoStandard, &fattr))
			return -1;

		LARGE_INTEGER size;
		size.HighPart = fattr.nFileSizeHigh;
		size.LowPart = fattr.nFileSizeLow;
		return size.QuadPart;
	}

#endif // WIN32
