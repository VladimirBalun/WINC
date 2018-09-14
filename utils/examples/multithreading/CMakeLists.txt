cmake_minimum_required (VERSION 3.8)

add_executable (MutexExample mutex_example.c ../../sources/mutex.c)
target_include_directories (MutexExample PRIVATE ../../include)

if (UNIX)
    target_link_libraries (MutexExample -lpthread)
endif ()