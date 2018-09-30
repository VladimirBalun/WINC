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

#include <winc/file_system/directory.h>
#include <winc/file_system/path.h>

int main()
{
    char* user_dir = get_user_directory();
    if (!is_exist_dir(user_dir))
    {
        fprintf(stderr, "User directory is absent.");
        free(user_dir);
        return SYSTEM_ERROR;
    }

    const char* new_catalog = "/tmp_directory_for_example";
    char test_dir[strlen(user_dir) + strlen(new_catalog) + 1];
    strcpy(test_dir, user_dir);
    strcat(test_dir, new_catalog);

    if (create_dir(test_dir))
        printf("Directory: \"%s\" was created.\n", test_dir);
    else
        fprintf(stderr, "Directory: \"%s\" wasn't created.\n", test_dir);

    if (remove_dir(test_dir))
        printf("Directory: \"%s\" was deleted.\n", test_dir);
    else
        fprintf(stderr, "Directory: \"%s\" wasn't deleted.\n", test_dir);

    free(user_dir);

    return EXIT_SUCCESS;
}
