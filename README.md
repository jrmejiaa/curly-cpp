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

GTest is a very well known testing framework of Google to test C++ code. I wanted to use for a long time with CMake, Google recommends Bazel but most of us know that Bazel is not a standard in the companies and therefore maybe not the best tool to learn. Although ex-Googlers missed a lot this tool. I based all the code in the tutorial of Matheus Gomes: [Integrating Google Test into CMake Projects](https://matgomes.com/integrate-google-test-into-cmake/). 

### Memory Leakage

A very simple code showing a memory leakage and using [ASan](https://github.com/google/sanitizers) flags to detect it. This is basically a Heap memory allocation and what happen when you are not careful enough. I used the flag `-fsanitize=leak` to detect leaks in the code. This feature is not perfect, but it is really helpful to detect small bugs in the code as soon as possible.

### Curly Copy

Some code to see the problems with Shallow copies and how to solve it using Copy constructor and Copy Assignment.

### Vector vs Arrays

A Basic code that shows the most important difference between Vector and Arrays. The vector growths dynamically, it will always be a continuous chunk of memory, but it will be increase during run-time. Meanwhile, from the beginning, the arrays needs to have a size from compilation-time. If the number of elements is known, it is better to not use Vector in extremely restricted environments. Nevertheless, the re-arranging process is very efficient according to the STD of C++.

The `Resource` class allows us to see this difference clearly, thanks to the `cout` messages in every case. As we expected, the vector object destroys and copies the objects on need. This according to a Growth Policy. Meanwhile, the array class only copies the elements that wants to be added to the container and only destroys all elements when it is out of scope. 

## Authors

* **Jairo Mejia** - [jrmejiaa](https://github.com/jrmejiaa)
* Several authors that gave me ideas and code to make this possible

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE) file for details leakage
