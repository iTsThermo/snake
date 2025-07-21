#include "Button.h"
#include <string>

Button::Button(unsigned int x, unsigned int y, const std::string& text)
{
    this->color_idle = sf::Color::White;
    this->color_hover = sf::Color::Red;
    this->color_pressed = sf::Color::Blue;

    this->text.setString(text);
    this->text.setFillColor(sf::Color::Black);
    this->font.loadFromFile("../ARIAL.TTF");
    this->text.setFont(font);
    this->text.setPosition(x / 3, y / 3);

    this->shape.setFillColor(this->color_idle);

    this->state = IDLE;

    this->shape.setSize({100,100});
    this->shape.setPosition(x / 3, y / 3);
}

Button::~Button()
{
}

const bool &Button::isPressed() const
{
    // TODO: insert return statement here
    return this->state == PRESSED;
}

const bool &Button::ishover() const
{
    // TODO: insert return statement here
    return this->state == HOVER;
}

void Button::update(const sf::RenderWindow &window)
{
    sf::Vector2f mouse_pos_view = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    if (this->shape.getGlobalBounds().contains(mouse_pos_view)){
        this->shape.setFillColor(this->color_hover);
        this->state = HOVER;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            this->shape.setFillColor(this->color_pressed);
            this->state = PRESSED;
        }
    }
    else {
        this->shape.setFillColor(this->color_idle);
        this->state = IDLE;
    }
}

void Button::render(sf::RenderTarget &target)
{
    target.draw(this->shape);
}

void Button::render_text(sf::RenderTarget &target)
{
    target.draw(this->text);
}
