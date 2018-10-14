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

function (winc_link_target_with_winc_library target library)
    if (UNIX)
        target_link_libraries (${target} ${WINC_OUTPUT_LIBS_DIR}/lib${library}.a)
    elseif (WIN32)
        target_link_libraries (${target} ${WINC_OUTPUT_LIBS_DIR}/${library}.lib)
    endif ()
endfunction ()

function (winc_add_dependency_with_winc_library target library)
    if (UNIX)
		add_dependencies (${target} ${WINC_OUTPUT_LIBS_DIR}/lib${library}.a)
    elseif (WIN32)
		add_dependencies (${target} ${WINC_OUTPUT_LIBS_DIR}/${library}.lib)
    endif ()
endfunction ()
