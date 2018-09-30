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

#include <winc/file_system/path.h>

void iteration_callback(const char* elem)
{
    printf("%s\n", elem);
}

int main()
{
    char* user_dir = get_user_directory();
    printf("User directory: %s\n", user_dir);

    char* curr_dir = get_current_directory();
    printf("Current working directory: %s\n", curr_dir);

    printf("Iteration in the user directory:\n");
    path_iterate(user_dir, iteration_callback);

    free(user_dir);
    free(curr_dir);

    return EXIT_SUCCESS;
}
