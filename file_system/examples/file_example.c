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

#include <stdio.h>

#include "winc/file_system/file.h"

int main()
{
    const char* source_file = "source_file.txt";
    const char* copied_file = "copied_file.txt";
    const char* renamed_file = "renamed_file.txt";

    if (create_file(source_file))
    {
        const char* data = "Hello world!";
        append_to_file(source_file, data);
        if (!copy_file(source_file, copied_file))
        {
            printf("File wasn't copied.");
            return EXIT_FAILURE;
        }
    }
    else
    {
        printf("File wasn't created.");
        return EXIT_FAILURE;
    }

    char* data_from_copied_file = read_file(copied_file);
    printf("Copied data: %s\n", data_from_copied_file);
    if (data_from_copied_file)
        free(data_from_copied_file);

    rename_file(copied_file, renamed_file);
    const char* new_data = "New hello world!";
    rewrite_file(renamed_file, new_data);
    printf("New size of renamed file: %lu\n", get_file_size(renamed_file));

    if (!remove_file(source_file))
        printf("File wasn't deleted.");
    if(!remove_file(renamed_file))
        printf("File wasn't deleted.");

    return EXIT_SUCCESS;
}
