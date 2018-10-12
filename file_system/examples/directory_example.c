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

#include "winc/file_system/directory.h"
#include "winc/file_system/path.h"

int main()
{
	// Getting the user directory and check if it exists
    char* user_dir = get_user_directory();
    if (!is_exist_dir(user_dir))
    {
        fprintf(stderr, "Fatal error! User directory is absent...\n");
        return SYSTEM_ERROR;
    }

	// Creating test name for new directory
    const char* new_catalog_name = "/name_directory_for_example";
	const size_t length_dir_name = strlen(user_dir) + strlen(new_catalog_name) + 1;
    char* dir_name = malloc(length_dir_name);
    strcpy_s(dir_name, length_dir_name, user_dir);
    strcat_s(dir_name, length_dir_name, new_catalog_name);

	// Creating a new directory
	if (create_dir(dir_name))
		printf("Directory: \"%s\" was created.\n", dir_name);
	else
		fprintf(stderr, "Warning! Directory: \"%s\" wasn't created...\n", dir_name);

	// Creating a new name for renaming directory
	const char* renamed_catalog_name = "/renamed_directory_for_example";
	const size_t length_renamed_dir_name = strlen(user_dir) + strlen(renamed_catalog_name) + 1;
	char* renamed_dir_name = malloc(length_renamed_dir_name);
	strcpy_s(renamed_dir_name, length_renamed_dir_name, user_dir);
	strcat_s(renamed_dir_name, length_renamed_dir_name, renamed_catalog_name);

	// Renamimg created directory
	if (rename_dir(dir_name, renamed_dir_name)) 
		printf("Directory: \"%s\" was renamed on \"%s\"...\n", dir_name, renamed_dir_name);
	else
		fprintf(stderr, "Warning! Directory: \"%s\" wasn't renamed...\n", dir_name);

	// Deleting renamed directory
	if (remove_dir(renamed_dir_name))
		printf("Directory: \"%s\" was deleted...\n", renamed_dir_name);
	else
		fprintf(stderr, "Warning! Directory: \"%s\" wasn't deleted...\n", renamed_dir_name);

	// Free up resources
    free(dir_name);
	free(renamed_dir_name);

    return EXIT_SUCCESS;
}
