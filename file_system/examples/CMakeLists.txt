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

set (EXAMPLES DirectoryExample FileExample PathExample)

add_executable (DirectoryExample directory_example.c ../sources/directory.c ../sources/path.c)
add_executable (FileExample file_example.c ../sources/file.c)
add_executable (PathExample path_example.c ../sources/path.c)

foreach (_example ${EXAMPLES})
    target_include_directories (${_example} PRIVATE ../include)
    target_include_directories (${_example} PRIVATE ../../utils/include)
endforeach ()