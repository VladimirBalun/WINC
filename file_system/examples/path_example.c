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

#include "winc/file_system/path.h"

int main()
{
    char* user_dir = get_user_directory();
    printf("User directory: %s\n", user_dir);

    char* current_dir = get_current_directory();
    printf("Current working directory: %s\n", current_dir);

	if (is_directory(user_dir))
		printf("Path: \"%s\" is directory.\n", user_dir);
	else 
		fprintf(stderr, "Path: \"%s\" is not directory.\n", user_dir);

	if (!is_file(current_dir))
		printf("Path: \"%s\" is not file.\n", current_dir);
	else
		fprintf(stderr, "Path: \"%s\" is file.\n", current_dir);

	// Free up resources
    free(user_dir);
    free(current_dir);

    return EXIT_SUCCESS;
}
