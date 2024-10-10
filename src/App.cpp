#include "App.hpp"

void Application::run()
{
    std::vector<int> array;
    auto icon=sf::Image{};
    int n;
    std::cout<<"N: ";
    std::cin>>n;
    float bar_width=(float)(this->screen_width)/(float)(2*n+1);
    float bar_height=(float)(this->screen_height-10)/(float)(n);
    for(int i=1; i<=n; i++){
        array.push_back(i*bar_height);
    }
    random_shuffle(array.begin(), array.end());
    sf::RenderWindow main_window(sf::VideoMode(this->screen_width, this->screen_height), "Sorting Algorithms Visualization");
    main_window.setFramerateLimit(60);
    icon.loadFromFile("img\\icon.png");
    main_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    sf::RectangleShape *shapes=new sf::RectangleShape[array.size()];
    for(int i=0; i<array.size(); i++){
        shapes[i].setSize(sf::Vector2f(bar_width, array[i]));
        shapes[i].setPosition(2*i*bar_width+bar_width, this->screen_height-array[i]);
        shapes[i].setFillColor(sf::Color::White);
    }
    while (main_window.isOpen())
    {
        sf::Event event;
        while(main_window.pollEvent(event)){
            if(event.type==sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                main_window.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                random_shuffle(array.begin(), array.end());
                for(int i=0; i<array.size(); i++){
                    shapes[i].setSize(sf::Vector2f(bar_width, array[i]));
                    shapes[i].setPosition(2*i*bar_width+bar_width, this->screen_height-array[i]);
                    shapes[i].setFillColor(sf::Color::White);
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)){
                bool swapped;
                for(int i=0; i<n-1; i++){
                    swapped=false;
                    for(int j=0; j<n-i-1; j++){
                        if(array[j]>array[j+1]){
                            int tmp;
                            tmp=array[j];
                            array[j]=array[j+1];
                            array[j+1]=tmp;
                            swapped=true;
                            main_window.clear();
                            for(int k=0; k<n; k++){
                                shapes[k].setSize(sf::Vector2f(bar_width, array[k]));
                                shapes[k].setPosition(2*k*bar_width+bar_width, this->screen_height-array[k]);
                                shapes[k].setFillColor(sf::Color::White);
                                main_window.draw(shapes[k]);
                            }
                            Sleep(100/n);
                            main_window.display();
                        }
                    }
                    if(!swapped)
                        break;
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::I)){
                for (int i=1; i<n; ++i){
                    int key=array[i];
                    int j=i-1;
                    while (j>=0 && array[j]>key){
                        array[j+1]=array[j];
                        j=j-1;
                        main_window.clear();
                        for(int k=0; k<n; k++){
                            shapes[k].setSize(sf::Vector2f(bar_width, array[k]));
                            shapes[k].setPosition(2*k*bar_width+bar_width, this->screen_height-array[k]);
                            shapes[k].setFillColor(sf::Color::White);
                            main_window.draw(shapes[k]);
                        }
                        Sleep(100/n);
                        main_window.display();
                    }
                    array[j+1]=key;
                }
            }
        }
        main_window.clear();
        for(int i=0; i<array.size(); i++){
            main_window.draw(shapes[i]);
        }
        main_window.display();
    }
}