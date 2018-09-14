#!/bin/bash

build_directory="build"

successful_build=0
cmake_not_intalled=-1
make_not_installed=-2

if ! [ -x "$(command -v cmake)" ];
then
    echo -n "Error! CMake isn't installed..."
    exit $cmake_not_intalled
fi

if ! [ -x "$(command -v make)" ];
then
    echo -n "Erroe! Make isn't installed..."
    exit $make_not_installed
fi

if [ -d "${build_directory}" ];
then
    rm -Rf $build_directory
fi

mkdir $build_directory
cd $build_directory
cmake ..
make

exit $successful_build