# Generating Core Dumps in C++

## Introduction

Core dumps are snapshots of a program's memory at the moment it crashes. They help debug segmentation faults and other critical issues by providing insight into the state of the program when it failed.

## Enabling Core Dumps

### Linux

Ensure core dumps are enabled:

```sh
ulimit -c unlimited
```

Verify the setting:

```sh
ulimit -c
```

Set the location for core dumps:

```sh
echo "/tmp/core.%e.%p" | sudo tee /proc/sys/kernel/core_pattern
```

### macOS

Enable core dumps:

```sh
ulimit -c unlimited
```

Check core dump settings:

```sh
sysctl kern.corefile
```

### Windows

Use Windows Error Reporting (WER) to generate crash dumps:

1. Open **Registry Editor** (`regedit`).
2. Navigate to `HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\Windows Error Reporting\LocalDumps`.
3. Set `DumpType` to `2` (Full dump).

## Writing a Crash Program (C++)

```cpp
#include <iostream>
#include <cstdlib>

void cause_crash() {
    int* ptr = nullptr;
    *ptr = 42; // Segmentation fault
}

int main() {
    std::cout << "Causing a crash..." << std::endl;
    cause_crash();
    return 0;
}
```

Compile and run:
```sh
g++ -g -o crash crash.cpp
./crash
```

## Locating Core Dumps

- Linux: `/tmp/core.*` (or location set in `core_pattern`).
- macOS: `/cores/core.*`.
- Windows: `C:\Users\Username\AppData\Local\CrashDumps`.

## Analyzing Core Dumps with GDB

```sh
gdb ./crash core
```

Inside GDB:

```sh
bt # Show backtrace
info registers # Show register states
```

## Disabling Core Dumps

To disable core dumps:
```sh
ulimit -c 0
```

For permanent settings, add it to `~/.bashrc` or `/etc/security/limits.conf`.

## Conclusion

Core dumps are a powerful debugging tool for analyzing program crashes. By enabling them and using GDB, you can diagnose issues effectively.
