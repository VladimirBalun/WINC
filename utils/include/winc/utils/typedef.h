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

#ifndef WINC_UTILS_TYPEDEF_H
#define WINC_UTILS_TYPEDEF_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdlib.h>

typedef int8_t bool;
#define true  1
#define false 0

#define FOREVER() for(;;)
#define LAMBDA(sign_) ({ sign_ _;})

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // WINC_UTILS_TYPEDEF_H
