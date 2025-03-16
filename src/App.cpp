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
    int col;
    std::cout<<"Bars' color (default: 0)[0 - White, 1 - Red, 2 - Green, 3 - Blue, 4 - Yellow, 5 - Magenta, 6 - Cyan]: ";
    std::cin>>col;
    switch(col)
    {
        case 1:
            this->barColor = sf::Color::Red;
        break;
        case 2:
            this->barColor = sf::Color::Green;
        break;
        case 3:
            this->barColor = sf::Color::Blue;
        break;
        case 4:
            this->barColor = sf::Color::Yellow;
        break;
        case 5:
            this->barColor = sf::Color::Magenta;
        break;
        case 6:
            this->barColor = sf::Color::Cyan;
        break;
        default:
            this->barColor = sf::Color::White;
        break;
    }
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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            this->selectionSort();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::L))
            this->shellSort();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C))
            this->cocktailSort();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::G))
            this->gnomeSort();
        this->updateFrame();
    }
}

void Application::updateFrame(void)
{
    const sf::Font font("./../fonts/DepartureMonoNerdFont-Regular.otf");
    sf::Text algorithmNameText(font, this->algorithmName);
    sf::Text algorithmTimeComplexityText(font, this->algorithmTimeComplexity);
    sf::Text algorithmSpaceComplexityText(font, this->algorithmSpaceComplexity);
    algorithmTimeComplexityText.setCharacterSize(20);
    algorithmSpaceComplexityText.setCharacterSize(20);
    algorithmTimeComplexityText.setPosition(sf::Vector2f(0.0f, 50.0f));
    algorithmSpaceComplexityText.setPosition(sf::Vector2f(0.0f, 80.0f));
    mainWindow.clear();
    for(int i=0; i<this->n; i++){
        this->bars[i]->setSize(sf::Vector2f(this->barWidth, this->array[i]));
        this->bars[i]->setPosition(sf::Vector2f(this->barWidth * (2 * i + 1), this->screenHeight - this->array[i]));
        this->bars[i]->setFillColor(this->barColor);
        this->mainWindow.draw(*bars[i]);
    }
    mainWindow.draw(algorithmNameText);
    mainWindow.draw(algorithmTimeComplexityText);
    mainWindow.draw(algorithmSpaceComplexityText);
    mainWindow.display();
}

void Application::shuffleArray(void)
{
    this->algorithmName = "";
    this->algorithmTimeComplexity = "";
    this->algorithmSpaceComplexity = "";
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
    this->algorithmName = "Bubble Sort";
    this->algorithmTimeComplexity = "Time: O(n^2)";
    this->algorithmSpaceComplexity = "Space: O(1)";
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
    this->algorithmName = "Insertion Sort";
    this->algorithmTimeComplexity = "Time: O(n^2)";
    this->algorithmSpaceComplexity = "Space: O(1)";
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
    this->algorithmName = "Heap Sort";
    this->algorithmTimeComplexity = "Time: O(n*log n)";
    this->algorithmSpaceComplexity = "Space: O(1)";
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
    this->algorithmName = "Quick Sort";
    this->algorithmTimeComplexity = "Time: O(n*log n)";
    this->algorithmSpaceComplexity = "Space: O(1)";
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
    this->algorithmName = "Merge Sort";
    this->algorithmTimeComplexity = "Time: O(n*log n)";
    this->algorithmSpaceComplexity = "Space: O(n)";
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

void Application::selectionSort()
{
    this->algorithmName = "Selection Sort";
    this->algorithmTimeComplexity = "Time: O(n^2)";
    this->algorithmSpaceComplexity = "Space: O(1)";
    for(int i=0; i<this->n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<this->n; j++)
            if(this->array[j] < this->array[minIndex])
                minIndex = j; 
        this->swap(this->array[i], this->array[minIndex]);
        this->updateFrame();
    }
}

void Application::shellSort()
{
    this->algorithmName = "Shell Sort";
    this->algorithmTimeComplexity = "Time: O(n^4/3)";
    this->algorithmSpaceComplexity = "Space: O(1)";
    for(int gap=n/2; gap>0; gap/=2){
        for(int i=gap; i<n; i++){
            int tmp = this->array[i];
            int j;            
            for(j=i; j >= gap && this->array[j-gap] > tmp; j -= gap){
                this->array[j] = this->array[j-gap];
                this->updateFrame();
            }
            this->array[j] = tmp;
            this->updateFrame();
        }
    }
}

void Application::cocktailSort()
{
    this->algorithmName = "Cocktail Sort";
    this->algorithmTimeComplexity = "Time: O(n^2)";
    this->algorithmSpaceComplexity = "Space: O(1)";
    bool swapped = true;
    int start = 0;
    int end = this->n-1;
    while(swapped){
        swapped = false;
        for(int i=start; i<end; i++){
            if(this->array[i] > this->array[i+1]){
                this->swap(this->array[i], this->array[i+1]);
                this->updateFrame();
                swapped = true;
            }
        }
        if(!swapped)
            break;
        swapped = false;
        end--;
        for(int i=end-1; i>=start; i--){
            if(this->array[i] > this->array[i+1]){
            this->swap(this->array[i], this->array[i+1]);
            this->updateFrame();
            swapped = true;
            }
        }
        start++;
    }
}

void Application::gnomeSort()
{
    this->algorithmName = "Gnome Sort";
    this->algorithmTimeComplexity = "Time: O(n^2)";
    this->algorithmSpaceComplexity = "Space: O(1)";
    int index = 0; 
    while(index < this->n){ 
        if(index == 0) 
            index++; 
        if(this->array[index] >= this->array[index-1]) 
            index++; 
        else{ 
            this->swap(this->array[index], this->array[index-1]);
            this->updateFrame(); 
            index--; 
        } 
    } 
}
