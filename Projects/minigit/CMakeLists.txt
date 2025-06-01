cmake_minimum_required(VERSION 3.10)
project(minigit VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(minigit
    src/main.cpp
    src/repository.cpp
    src/object_store.cpp
    src/sha1.cpp
    src/terminal_utils.cpp
    src/status.cpp
    src/index.cpp
)

