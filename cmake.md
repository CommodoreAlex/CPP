# CMake Guide: Creating and Managing Projects

## Introduction
CMake is a cross-platform build system generator that helps manage the build process of software projects in a compiler-independent manner. This guide will walk you through setting up a project, writing CMakeLists.txt, configuring, building, and managing dependencies with CMake.

## Installation

### Linux (Ubuntu/Debian)
```sh
sudo apt update
sudo apt install cmake
```

### Windows
1. Download CMake from [cmake.org](https://cmake.org/download/)
2. Install and add it to the system `PATH` during installation.

## Basic CMake Project Structure
```
project_root/
│── CMakeLists.txt
│── src/
│   ├── main.cpp
│── build/
```

## Writing a Basic CMakeLists.txt
Create a `CMakeLists.txt` file in the root directory of your project.
```cmake
cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(MyExecutable src/main.cpp)
```

## Building the Project
```sh
mkdir build
cd build
cmake ..
make  # or cmake --build .
```

The compiled executable will be in the `build/` directory.

## Managing Dependencies with CMake
CMake provides built-in support for fetching dependencies using `FetchContent` or `find_package`.

### Using FetchContent
```cmake
include(FetchContent)
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.10.5
)
FetchContent_MakeAvailable(json)

add_executable(MyExecutable src/main.cpp)
target_link_libraries(MyExecutable PRIVATE nlohmann_json::nlohmann_json)
```

### Using find_package
```cmake
find_package(OpenCV REQUIRED)
add_executable(MyExecutable src/main.cpp)
target_link_libraries(MyExecutable PRIVATE ${OpenCV_LIBS})
```
Ensure you have the dependency installed before using `find_package`.

## Configuring and Installing
```cmake
install(TARGETS MyExecutable DESTINATION bin)
```
Run:
```sh
cmake --install build --prefix /usr/local
```

## Debugging with CMake
```sh
cmake -DCMAKE_BUILD_TYPE=Debug ..
gdb ./MyExecutable
```

## Conclusion
CMake is a powerful tool for managing C++ projects, offering flexibility and cross-platform support. By following these steps, you can efficiently configure, build, and manage dependencies in your projects.

