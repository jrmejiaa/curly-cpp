# Curly CPP 

Please don't think twice about the name. Github suggest it me and I like it. Here you will find some basic code of C++ and CMake. My idea basically is to put here some of my findings of C++ and CMake while I am improving my skills in the subject. All the projects are going to be made with CMake as building tool and all the projects are going to be in C++ 20.

## Getting Started

### Prerequisites

* A PC that can run cmake 3.X and gcc 12
* Your IDE/Editor of your choice

### Installing

The projects are separated by folders. Therefore every folder contains a project itself. You only need to create a build folder to run any project of the repository. At the moment, I don't have any logic to run all the project at once, maybe later :D

```bash
# At the root of the folder
mkdir build && cd build && cmake ../<name-of-project> && make

# Output at the end looks like this....
[ 75%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
[ 83%] Linking CXX static library ../../../lib/libgmock.a
[ 83%] Built target gmock
[ 91%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
[100%] Linking CXX static library ../../../lib/libgmock_main.a
[100%] Built target gmock_main
```

Depending on the project the executable differs, so it is not that easy to know what you would do next.

Happy Coding!

## Projects

### GTest with CMake

GTest is a very well known testing framework of Google to test C++ code. I wanted to use for a long time with CMake, Google recommends Bazel but most of us know that Bazel is not a standard in the companies and therefore maybe not the best tool to learn. Although ex-Googlers missed a lot this tool. I based all the code in the tutorial of Matheus Gomes [Integrating Google Test into CMake Projects](https://matgomes.com/integrate-google-test-into-cmake/). 

## Authors

* **Jairo Mejia** - *Work for the new version without FreeRTOS* - [jrmejiaa](https://github.com/jrmejiaa)
* Several authors that gave me ideas and code to make this possible

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE) file for details