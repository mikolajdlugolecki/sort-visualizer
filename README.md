# Sorting Algorithms Visualizer


## Table of Contents
* [Preview][#preview]
* [Requirements](#requirements)
* [Installation](#installation)
* [Controls][#controls]

## Preview

## Requirements
* [SFML](https://www.sfml-dev.org/) (v3.0.0 or higher)
* [CMake](https://cmake.org) (v3.31.6 or higher)

## Installation
1. **Clone repository**:
```bash
git clone https://github.com/mikolajdlugolecki/sort-visualizer.git
```
2. **Create and go into _build_ directory**:
```bash
mkdir build && cd build
```
3. **Create CMake dependencies**:
```bash
cmake .. && cmake --build .
```
4. **Build the project**:
```bash
make
```
5. **Run the program**:
```bash
./visualizer
```

## Controls
| **Key**   | **Action**           |
| --------- | -------------------- |
| **Space** | _Shuffle the array_  |
| **B**     | _Bubble Sort_        |
| **I**     | _Insertion Sort_     |
