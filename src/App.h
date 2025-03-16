#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

#include <SFML/Graphics.hpp>

#define WIDTH 1600
#define HEIGHT 900
#define TITLE "Sorting Algorithms Visualizer"

class Application
{
public:
    Application();
    ~Application();
    void run(void);
private:
    unsigned short int screenWidth = WIDTH;
    unsigned short int screenHeight = HEIGHT;
    sf::RenderWindow mainWindow;
    std::string mainWindowTitle = TITLE;
    bool canPressAgain;
    std::vector<int> array;
    int n;
    float barWidth;
    float barHeight;
    sf::Color barColor;
    std::string algorithmName;
    std::string algorithmTimeComplexity;
    std::string algorithmSpaceComplexity;
    std::vector<sf::RectangleShape*> bars;
    void updateFrame(void);
    void shuffleArray(void);
    void swap(int &a, int &b);
    void bubbleSort();
    void insertionSort();
    void heapSort();
    void constructHeap(std::vector<int>& arr, int n, int i);
    void quickSort(int left, int right);
    int divide(int left, int right);
    void mergeSort(int left, int right);
    void merge(int left, int mid, int right);
    void selectionSort();
    void shellSort();
    void cocktailSort();
    void gnomeSort();
};
