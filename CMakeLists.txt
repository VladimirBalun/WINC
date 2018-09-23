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

project (WINC)

set (WINC_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set (WINC_CMAKE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set (WINC_BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)
set (WINC_OUTPUT_LIBS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)
set (WINC_OUTPUT_EXAMPLES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/examples)

option (ENABLE_EXAMPLES "Enable different exa,ples for libraries" ON)
option (WINC_ENABLE_FILE_SYTEM "Enable library for file system" ON)

set (WINC_LIBRARIES "")
add_subdirectory (utils)
list (APPEND WINC_LIBRARIES "lib${PROJECT_NAME}Utils")

if (WINC_ENABLE_FILE_SYTEM)
    add_subdirectory (file_system)
    list (APPEND WINC_LIBRARIES "lib${PROJECT_NAME}FileSystem")
endif ()

foreach (library ${WINC_LIBRARIES})
    message (STATUS "Building: ${library}...")
endforeach ()

if (ENABLE_EXAMPLES)
    message (STATUS "Examples were included in the building.")
    message (STATUS "Building examples...")
endif ()