#include <vector>
#include <windows.h>
#include <SFML/Graphics.hpp>

void bubble_sort(std::vector<int> &arr, sf::RectangleShape *shapes, sf::RenderWindow &window);
void heap_sort(std::vector<int> &arr);
void selection_sort(std::vector<int> &arr);
void insertion_sort(std::vector<int> &arr);
void merge_sort(std::vector<int> &arr);
void quick_sort(std::vector<int> &arr);
void counting_sort(std::vector<int> &arr);
void shell_sort(std::vector<int> &arr);