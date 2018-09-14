cmake_minimum_required (VERSION 3.8)

add_executable (ListExample list_example.c ../../sources/list.c)
target_include_directories (ListExample PRIVATE ../../include)