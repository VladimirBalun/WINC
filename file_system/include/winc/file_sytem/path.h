#ifndef WINC_FILE_SYSTEM_PATH_H
#define WINC_FILE_SYSTEM_PATH_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <winc/utils/typedef.h>

bool is_path(const char* name);
bool is_file(const char* name);

const char* get_user_directory();
const char* get_current_directory();

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // WINC_FILE_SYSTEM_PATH_H
