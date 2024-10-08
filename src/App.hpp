#pragma once

#include "Algorithms.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define WIDTH 1600
#define HEIGHT 900

class Application{
    public:
    unsigned short int screen_width=WIDTH, screen_height=HEIGHT; 
    void run();
};