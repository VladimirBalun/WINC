#include <stdio.h>
#include <stdlib.h>

#include "winc/file_sytem/file.h"

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
