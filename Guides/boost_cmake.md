# Boost C++ on Linux: Guide with CMake Integration

## 1. Install Boost

Install Boost development packages:
```bash
sudo apt update
sudo apt install libboost-all-dev
```

---

## 2. Project Layout Example

```bash
boost_demo/
├── CMakeLists.txt
└── main.cpp
```

---

## 3. Sample Code: `main.cpp`

```cpp
#include <boost/filesystem.hpp>
#include <iostream>
using namespace std;

int main() {
    boost::filesystem::path p{"test.txt"};
    if (boost::filesystem::exists(p)) {
        cout << p << " exists.\n";
    } else {
        cout << p << " does not exist.\n";
    }
    return 0;
}
```

---

## 4. CMakeLists.txt: Basic Setup

```cmake
cmake_minimum_required(VERSION 3.10)
project(BoostDemo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS filesystem system)

add_executable(main main.cpp)
target_link_libraries(main Boost::filesystem Boost::system)
```

---

## 5. Key Notes on `find_package`

- `REQUIRED` ensures configuration fails if Boost is not found.
    
- `COMPONENTS` specifies which Boost modules are needed (e.g., `filesystem`, `thread`, etc.).
    
- CMake creates imported targets like `Boost::filesystem` for linking.
    

---

## 6. Building the Project

```bash
mkdir -p build && cd build
cmake ..
make
./main
```

---

## 7. Header-Only Libraries in CMake

Boost includes many header-only libraries (e.g., `boost::algorithm`, `boost::lexical_cast`) that don’t require linking.

In such cases, you don't need `COMPONENTS` or `target_link_libraries`:
```cmake
find_package(Boost REQUIRED) # No components
target_include_directories(main PRIVATE ${Boost_INCLUDE_DIRS})
```

---

## 8. Advanced: Static vs Dynamic Linking

If you want to **force static linking**, you can set:
```cmake
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS filesystem system)
```

If Boost is installed in a **non-standard location**, specify it:
```cmake
set(BOOST_ROOT "/path/to/boost")
set(CMAKE_PREFIX_PATH "/path/to/boost")
find_package(Boost REQUIRED COMPONENTS ...)
```

---

## 9. Troubleshooting Tips

|Issue|Solution|
|---|---|
|Boost not found|Check that `libboost-all-dev` is installed|
|Static linking errors|Ensure `.a` versions of Boost libs exist (`libboost_*.a`)|
|Header-only lib not working|Confirm you don’t need to link; only include directories|
|CMake can't find Boost|Explicitly set `BOOST_ROOT` or `CMAKE_PREFIX_PATH`|
|Multiple Boost versions conflict|Use a clean environment or set `BOOST_INCLUDEDIR` manually|

---

## 10. Boost CMake Documentation

- [Boost CMake Integration](https://cmake.org/cmake/help/latest/module/FindBoost.html)
    
- [Boost.org Docs](https://www.boost.org/libraries/latest/grid/)
