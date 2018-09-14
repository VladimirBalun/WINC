cmake_minimum_required (VERSION 3.8)

set (EXAMPLES FileExample)

add_executable (FileExample file_example.c ../sources/file.c)

foreach (_example ${EXAMPLES})
    target_include_directories (${_example} PRIVATE ../include)
    target_include_directories (${_example} PRIVATE ../../utils/include)
endforeach ()
