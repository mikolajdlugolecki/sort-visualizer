# Sorting Algorithms Visualizer
This program uses the SFML library to visualize how different sorting algorithms work.

## Table of Contents
* [Preview](#preview)
* [Requirements](#requirements)
* [Installation](#installation)
* [Algorithms](#algorithms)
* [Controls](#controls)

## Preview
https://github.com/user-attachments/assets/271d1a96-ca2c-44f5-a007-fc345084b848

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

## Algorithms
* [Bubble Sort](https://en.wikipedia.org/wiki/Bubble_sort)
* [Insertion Sort](https://en.wikipedia.org/wiki/Insertion_sort)
* [Heap Sort](https://en.wikipedia.org/wiki/Heapsort)
* [Quick Sort](https://en.wikipedia.org/wiki/Quicksort)
* [Merge Sort](https://en.wikipedia.org/wiki/Merge_sort)
* [Selection Sort](https://en.wikipedia.org/wiki/Selection_sort)
* [Shell Sort](https://en.wikipedia.org/wiki/Shellsort)
* [Cocktail Sort](https://en.wikipedia.org/wiki/Cocktail_shaker_sort)
* [Gnome Sort](https://en.wikipedia.org/wiki/Gnome_sort)
* [Radix Sort](https://en.wikipedia.org/wiki/Radix_sort) TODO
* [Bucket Sort](https://en.wikipedia.org/wiki/Bucket_sort) TODO

## Controls
| **Key**   | **Action**          |
| --------- | ------------------- |
| **ESC**   | _Close program_     |
| **Space** | _Shuffle the array_ |
| **B**     | _Bubble Sort_       |
| **I**     | _Insertion Sort_    |
| **H**     | _Heap Sort_         |
| **Q**     | _Quick Sort_        |
| **M**     | _Merge Sort_        |
| **S**     | _Selection Sort_    |
| **L**     | _Shell Sort_        |
| **C**     | _Cocktail Sort_     |
| **G**     | _Gnome Sort_        |