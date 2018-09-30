#
# Copyright 2018 Vladimir Balun
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

cmake_minimum_required (VERSION 3.8)

include (${WINC_CMAKE_DIR}/TargetProperties.cmake)

set (LIB_NAME ${PROJECT_NAME}Utils)
set (WINC_UTILS_DIR ${CMAKE_CURRENT_SOURCE_DIR})

file (GLOB_RECURSE HEADERS include/*.h)
file (GLOB_RECURSE SOURCES sources/*.c)

if (ENABLE_EXAMPLES)
    add_subdirectory (examples)
endif ()

add_library (${LIB_NAME} STATIC ${HEADERS} ${SOURCES})
winc_set_target_properties_for_lib (${LIB_NAME})
target_include_directories (${LIB_NAME} PRIVATE ./include)
