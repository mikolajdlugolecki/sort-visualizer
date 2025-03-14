#include "App.h"

Application::Application()
{
    std::cout<<"Elements in array [N]: ";
    std::cin>>this->n;
    this->barWidth = (float)(this->screenWidth) / (float)(2 * n + 1);
    this->barHeight = (float)(this->screenHeight - 10) / (float)(n);
    for(int i=1; i<=n; i++)
        this->array.push_back(i * this->barHeight);
    random_shuffle(this->array.begin(), this->array.end());
    this->mainWindow.create(sf::VideoMode({this->screenWidth, this->screenHeight}), this->mainWindowTitle);
    this->mainWindow.setFramerateLimit(60);
    this->canPressAgain = true;
    for(int i=0; i<this->n; i++)
        this->bars.push_back(new sf::RectangleShape);
    this->updateFrame();
}

Application::~Application()
{
    this->array.clear();
    for(auto& bar : this->bars)
        delete bar;
    this->bars.clear();
}

void Application::run(void)
{
    while(mainWindow.isOpen()){
        while(const std::optional event = mainWindow.pollEvent()){
            if(event->is<sf::Event::Closed>())
                mainWindow.close();
            else if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
                if(keyPressed->code == sf::Keyboard::Key::Space && canPressAgain){
                    this->shuffleArray();
                    this->canPressAgain = false;
                }
            }
            else if(const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()){
                if(keyReleased->code == sf::Keyboard::Key::Space)
                    this->canPressAgain = true;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            mainWindow.close();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B))
            this->bubbleSort();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::I))
            this->insertionSort();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::H))
            this->heapSort();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
            this->quickSort(0, this->n-1);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M))
            this->mergeSort(0, this->n-1);
        this->updateFrame();
    }
}

void Application::updateFrame(void)
{
    mainWindow.clear();
    for(int i=0; i<this->n; i++){
        this->bars[i]->setSize(sf::Vector2f(this->barWidth, this->array[i]));
        this->bars[i]->setPosition(sf::Vector2f(this->barWidth * (2 * i + 1), this->screenHeight - this->array[i]));
        this->bars[i]->setFillColor(sf::Color::White);
        this->mainWindow.draw(*bars[i]);
    }
    mainWindow.display();
}

void Application::shuffleArray(void)
{
    random_shuffle(this->array.begin(), this->array.end());
    this->updateFrame();
}

void Application::swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void Application::bubbleSort()
{
    bool swapped;
    for(int i=0; i<n-1; i++){
        swapped = false;
        for(int j=0; j<n-i-1; j++)
            if(this->array[j] > this->array[j+1]){
                this->swap(this->array[j], this->array[j+1]);
                swapped = true;
                this->updateFrame();
            }
        if(!swapped)
            break;
    }
}

void Application::insertionSort()
{
    for(int i=1; i<this->n; ++i){
        int key = this->array[i];
        int j = i-1;
        while(j >= 0 && this->array[j] > key){
            this->array[j+1] = this->array[j];
            j--;
            this->updateFrame();
        }
        this->array[j+1] = key;
        this->updateFrame();
    }
}

void Application::heapSort()
{
    for(int i=n/2-1; i>=0; i--)
        constructHeap(this->array, this->n, i);
    for(int i=n-1; i>0; i--) {
        this->swap(this->array[0], this->array[i]);
        constructHeap(this->array, i, 0);
        this->updateFrame();
    }
}

void Application::constructHeap(std::vector<int> &arr, int n, int i)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l < n && arr[l] > arr[largest])
        largest = l;
    if(r < n && arr[r] > arr[largest])
        largest = r;
    if(largest != i){
        this->swap(arr[i], arr[largest]);
        this->updateFrame();
        constructHeap(arr, n, largest);
    }
}

void Application::quickSort(int left, int right)
{
    if(left < right){
        int pivot = this->divide(left, right);
        quickSort(left, pivot-1);
        quickSort(pivot+1, right);
    }
}

int Application::divide(int left, int right)
{
    int pivot = this->array[right];
    int i = left-1;
    for (int j=left; j<=right-1; j++){
        if(this->array[j] <= pivot){
            i++;
            this->swap(this->array[i], this->array[j]);
            this->updateFrame();
        }
    }
    this->swap(this->array[i+1], this->array[right]);
    this->updateFrame();
    return i+1;
}

void Application::mergeSort(int left, int right)
{
    if(left < right){
        int mid = left+(right-left)/2;
        mergeSort(left, mid);
        mergeSort(mid+1, right);
        merge(left, mid, right);
    }
}

void Application::merge(int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid-left+1;
    int n2 = right-mid;
    std::vector<int> leftVec(n1), rightVec(n2);
    for(i=0; i<n1; i++)
        leftVec[i] = this->array[left+i];
    for (j=0; j<n2; j++)
        rightVec[j] = this->array[mid+1+j];
    i = 0;
    j = 0;
    k = left;
    while(i < n1 && j < n2){
        if(leftVec[i] <= rightVec[j]){
            this->array[k] = leftVec[i];
            this->updateFrame();
            i++;
        }else{
            this->array[k] = rightVec[j];
            this->updateFrame();
            j++;
        }
        k++;
    }
    while(i < n1){
        this->array[k] = leftVec[i];
        this->updateFrame();
        i++;
        k++;
    }
    while(j < n2){
        this->array[k] = rightVec[j];
        this->updateFrame();
        j++;
        k++;
    }
}
