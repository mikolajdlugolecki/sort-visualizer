#pragma once

#include "Algorithms.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

#include <SFML/Graphics.hpp>

#define WIDTH 1600
#define HEIGHT 900

class Application
{
public:
    unsigned short int screen_width = WIDTH;
    unsigned short int screen_height = HEIGHT; 
    void run(void);
};
