#include "App.hpp"

void Application::run(){
    srand(time(NULL));
    std::vector<int> array;
    auto icon=sf::Image{};
    int size;
    std::cin>>size;
    float bar_width=(float)this->screen_width/(float)(2*size+1);
    for(int i=0; i<size; i++){
        array.push_back(rand()%this->screen_height);
    }
    sf::RenderWindow main_window(sf::VideoMode(this->screen_width, this->screen_height), "Sorting Algorithms Visualization");
    main_window.setFramerateLimit(60);
    icon.loadFromFile("img\\icon.png");
    main_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    sf::RectangleShape *shapes=new sf::RectangleShape[array.size()];
    for(int i=0; i<array.size(); i++){
        shapes[i].setSize(sf::Vector2f(bar_width, array[i]));
        shapes[i].setPosition(2*i*bar_width+bar_width, this->screen_height-array[i]);
        shapes[i].setFillColor(sf::Color::Green);
    }
    unsigned short int counter=0, prev_selected=0;
    while (main_window.isOpen())
    {
        sf::Event event;
        shapes[counter].setFillColor(sf::Color::Cyan);
        while(main_window.pollEvent(event)){
            if(event.type==sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                main_window.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                bubble_sort(array);
                for(int i=0; i<array.size(); i++){
                    shapes[i].setSize(sf::Vector2f(bar_width, array[i]));
                    shapes[i].setPosition(2*i*bar_width+bar_width, this->screen_height-array[i]);
                    shapes[i].setFillColor(sf::Color::Green);
                }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                if(counter>0){
                    prev_selected=counter;
                    counter--;
                    shapes[counter].setFillColor(sf::Color::Cyan);
                    shapes[prev_selected].setFillColor(sf::Color::Green);
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                if(counter<size-1){
                    prev_selected=counter;
                    counter++;
                    shapes[counter].setFillColor(sf::Color::Cyan);
                    shapes[prev_selected].setFillColor(sf::Color::Green);
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