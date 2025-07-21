#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

enum BUTTON_STATE{
    IDLE = 0,
    HOVER = 1,
    PRESSED = 2
};

class Button {
    public:
        Button(sf::Vector2f mouse_position);
        ~Button();

        const bool& isPressed() const;
        const bool& ishover() const;

        void update(const sf::RenderWindow& window);
        void render(sf::RenderTarget& target);
    
    private:
        sf::RectangleShape shape;
        sf::Color color_hover;
        sf::Color color_idle;
        sf::Color color_pressed;
        int state;
};