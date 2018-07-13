#!/bin/bash

build() {
    cmake -DOPENSSL_ROOT_DIR=/usr/local/Cellar/openssl/1.0.2o_1/include .
}

clean() {
    rm cmake_install.cmake && rm -r CMakeFiles && rm -f CMakeCache.txt
}

case $1 in
    "build") build; ;;
    "clean") clean; ;;
esac;
