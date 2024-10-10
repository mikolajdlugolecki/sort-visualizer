#include "Algorithms.hpp"

void bubble_sort(std::vector<int> &arr, sf::RectangleShape *shapes, sf::RenderWindow &window)
{
    int n=arr.size(), tmp;
    float tmp_x, tmp_y;
    bool swapped;
    for(int i=0; i<n-1; i++){
        swapped=false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                shapes[j].setFillColor(sf::Color::Cyan);
                shapes[j+1].setFillColor(sf::Color::Cyan);
                tmp_x=shapes[j].getPosition().x;
                tmp_y=shapes[j].getPosition().y;
                shapes[j].setPosition(shapes[j+1].getPosition().x, shapes[j+1].getPosition().y);
                shapes[j+1].setPosition(tmp_x, tmp_y);
                Sleep(100);
                window.draw(shapes[j]);
                window.draw(shapes[j+1]);
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
                shapes[j].setFillColor(sf::Color::White);
                shapes[j+1].setFillColor(sf::Color::White);
                swapped=true;
            }
        }
        if(!swapped)
            break;
    }
}

void heap_sort(std::vector<int> &arr)
{

}

void selection_sort(std::vector<int> &arr)
{

}

void insertion_sort(std::vector<int> &arr)
{

}

void merge_sort(std::vector<int> &arr)
{

}

void quick_sort(std::vector<int> &arr)
{

}

void counting_sort(std::vector<int> &arr)
{

}

void shell_sort(std::vector<int> &arr)
{

}