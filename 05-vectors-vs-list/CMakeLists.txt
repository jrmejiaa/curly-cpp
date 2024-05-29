cmake_minimum_required(VERSION 3.16)
project(MultiplyTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

AUX_SOURCE_DIRECTORY(include INCLUDES)
AUX_SOURCE_DIRECTORY(src SOURCES)

add_executable(vectors-vs-list ${SOURCES})

target_compile_options(vectors-vs-list PRIVATE -Wno-psabi -Wall -Werror -fdiagnostics-color=always -fsanitize=leak)
target_link_options(vectors-vs-list PRIVATE -fsanitize=leak)

# add_subdirectory(test)
