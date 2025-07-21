#ifndef BUTTON_H
#define BUTTON_H
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

enum BUTTON_STATE{
    IDLE = 0,
    HOVER = 1,
    PRESSED = 2
};

class Button {
    public:
        Button(unsigned int x, unsigned int y, const std::string& text);
        ~Button();

        const bool& isPressed() const;
        const bool& ishover() const;

        void update(const sf::RenderWindow& window);
        void render(sf::RenderTarget& target);
        void render_text(sf::RenderTarget& target);
    
    private:
        sf::RectangleShape shape;
        sf::Color color_hover;
        sf::Color color_idle;
        sf::Color color_pressed;
        sf::Text text;
        sf::Font font;
        int state;
};

#endif
