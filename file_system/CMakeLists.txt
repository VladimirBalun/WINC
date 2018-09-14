cmake_minimum_required (VERSION 3.8)

set (LIB_NAME ${PROJECT_NAME}FileSystem)

file (GLOB_RECURSE HEADERS include/*.h)
file (GLOB_RECURSE SOURCES sources/*.c)

if (ENABLE_EXAMPLES)
    add_subdirectory (examples)
endif ()

add_library (${LIB_NAME} STATIC ${SOURCES})
target_include_directories (${LIB_NAME} PRIVATE ./include)
target_include_directories (${LIB_NAME} PRIVATE ../utils/include)