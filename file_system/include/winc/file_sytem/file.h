#ifndef WINC_FILE_SYSTEM_FILE_H
#define WINC_FILE_SYSTEM_FILE_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "winc/utils/typedef.h"

bool create_file(const char* file_name);
bool remove_file(const char* file_name);
bool copy_file(const char* from_file_name, const char* to_file_name);
bool move_file(const char* file_name, const char* new_file_name);
bool rename_file(const char* old_file_name, const char* new_file_name);

bool create_sym_link(const char *file_name, const char *link_name);
bool create_hard_link(const char *file_name, const char *link_name);

char* read_file(const char* file_name);
void rewrite_file(const char* file_name, const char* data);
void append_to_file(const char* file_name, const char* data);

long int get_file_size(const char* file_name);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // WINC_FILE_SYSTEM_FILE_H
