cmake_minimum_required(VERSION 3.16)
project(MultiplyTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

AUX_SOURCE_DIRECTORY(include INCLUDES) 
AUX_SOURCE_DIRECTORY(src SOURCES) 

add_executable(curly-copy ${SOURCES})

target_compile_options(curly-copy PRIVATE -Wall -Werror -Wextra -fdiagnostics-color=always -fsanitize=leak)
target_link_options(curly-copy PRIVATE -fsanitize=leak)