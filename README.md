# Software Development 1 — E-sports Scouting & Recruitment System

Group 4 assignment project. A C++ console application used by a professional
e-sports team to identify and recruit new players.

## Domain

- **Players** — professional gamers being scouted
- **Games** — competitive game statistics
- **Fixtures** — scheduled matches against opponents

## Structure

The solution uses only **structures** (no classes), as required by the
assignment specification.

| File | Purpose |
| --- | --- |
| `main.cpp` | Entry point — starts the menu loop |
| `main_functions.h` / `.cpp` | Shared structures (`player`, `game`, `fixture`) and a placeholder `example` function |
| `guo_functions.h` / `.cpp` | Functions implemented by Guo — screen/menu, parameter passing, recursion |
| `function_tests.cpp` | Google Test (gtest) unit tests (runs via CMake) |

## Topics covered (Guo)

- **Screen / Menu** — console menu navigation
- **Parameter Passing** — by value, array of structs, by pointer, by reference, pointer-by-reference
- **Recursion** — recursive sum, recursive search, factorial

## Build

### Visual Studio
Open `Assignment/Assignment.slnx` and build.

### CMake (includes gtest tests)
```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build
```
