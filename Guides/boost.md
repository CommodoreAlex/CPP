# Boost C++ on Linux: Quick Start Guide

## 1. Install Boost

Use your package manager to install Boost headers and precompiled binaries:
```bash
sudo apt update sudo apt install libboost-all-dev
```

> For minimal install:  
> `sudo apt install libboost-dev`

---
## 2. Compile a Boost Program

Here’s a simple example using **Boost Filesystem**:
```cpp
// file_check.cpp
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

### Compile with g++ or CMAKE:

```bash
g++ -std=c++17 file_check.cpp -o file_check -lboost_filesystem -lboost_system ./file_check
```

---
## 3. Commonly Used Libraries

|Library|Link Name|Description|
|---|---|---|
|Boost.Filesystem|`-lboost_filesystem`|File and directory operations|
|Boost.System|`-lboost_system`|Required by many other Boost libraries|
|Boost.Thread|`-lboost_thread`|Multithreading support|
|Boost.Regex|`-lboost_regex`|Regular expressions|
|Boost.Date_Time|`-lboost_date_time`|Date and time utilities|
|Boost.Serialization|`-lboost_serialization`|Object serialization|

---
## 4. Header-Only Libraries

Some Boost libraries do **not** need linking:
```cpp
#include <boost/algorithm/string.hpp>

std::string text = "Hello World";
boost::to_upper(text); // HELLO WORLD
```

Compile like this (no `-lboost_...` needed):
```bash
g++ -std=c++17 string_ops.cpp -o string_ops
```

---
## 5. Documentation

Official Boost documentation: https://www.boost.org/doc/
