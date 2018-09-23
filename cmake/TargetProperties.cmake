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

function (winc_set_target_properties_for_lib library)
    set_target_properties(${library} PROPERTIES
            ARCHIVE_OUTPUT_DIRECTORY ${WINC_OUTPUT_LIBS_DIR}
            LIBRARY_OUTPUT_DIRECTORY ${WINC_OUTPUT_LIBS_DIR})
endfunction()

function (winc_set_target_properties_for_example example)
    set_target_properties(${example} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${WINC_OUTPUT_EXAMPLES_DIR})
endfunction()