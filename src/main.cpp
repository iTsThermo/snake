#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

void menu(){
    sf::RenderWindow window(sf::VideoMode({1080,720}), "Main Menu");

    sf::Color backgroundColor = sf::Color::Green;

    // Import Arial font 
    sf::Font ariel;
    ariel.loadFromFile("../ARIAL.TTF");

    // Create start, exit and main menu fonts
    sf::Text snake_menu_text;
    snake_menu_text.setFont(ariel);
    snake_menu_text.setString("SNAKE GAME");
    snake_menu_text.setFillColor(sf::Color::Black);
    
    sf::Text start_text;
    start_text.setFont(ariel);
    start_text.setString("Start");
    start_text.setFillColor(sf::Color::Black);

    sf::Text exit_text;
    exit_text.setFont(ariel);
    exit_text.setString("Exit");
    exit_text.setFillColor(sf::Color::Black);

    // Create rectangles for buttons
    sf::RectangleShape start_button({100, 50});
    sf::RectangleShape exit_button({100, 50});

    // Get window size 
    sf::Vector2u window_size = window.getSize();
    std::cout << std::endl <<"X:" << window_size.x << "Y:" << window_size.y;

    // Set positions for nuttons, and text
    start_text.setPosition(window_size.x / 2.75, window_size.y / 2);
    start_button.setPosition(window_size.x / 2.75, window_size.y / 2);
    
    exit_text.setPosition(window_size.x / 1.75, window_size.y / 2);
    exit_button.setPosition(window_size.x / 1.75, window_size.y / 2);

    snake_menu_text.setPosition(window_size.x / 2.25, window_size.y / 3);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Set the background color
        window.clear(backgroundColor);

        window.draw(snake_menu_text);

        window.draw(exit_button);
        window.draw(start_button);
        
        window.draw(exit_text);
        window.draw(start_text);


        window.display();
    }
}

int main()
{
    menu();
}
