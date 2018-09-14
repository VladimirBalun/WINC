cmake_minimum_required (VERSION 3.8)

project (WINC)
set(WINC_LIBRARIES "")

option(ENABLE_EXAMPLES "Enable different exa,ples for libraries" ON)
option(WINC_ENABLE_FILE_SYTEM "Enable library for file system" ON)

add_subdirectory (utils)
list(APPEND WINC_LIBRARIES "lib${PROJECT_NAME}Utils")

if (WINC_ENABLE_FILE_SYTEM)
    add_subdirectory (file_system)
    list(APPEND WINC_LIBRARIES "lib${PROJECT_NAME}FileSystem")
endif()

foreach(library ${WINC_LIBRARIES})
    message(STATUS "Building: ${library}")
endforeach()