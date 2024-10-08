#include "Algorithms.hpp"

void bubble_sort(std::vector<int> &arr){
    int n = arr.size(), tmp;
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}