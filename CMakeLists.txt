cmake_minimum_required(VERSION 3.3)
project(Huffman)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    decode.c
    encode.c
    functions.c
    functions_declarations.h
    hash.c
    hash_declarations.h
    Queue.c main.c main.h)

add_executable(Huffman ${SOURCE_FILES})