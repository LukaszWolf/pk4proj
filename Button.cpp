#include "Button.h"
#include <iostream>

Button::Button() {};


Button::Button(sf::Vector2f position, sf::Vector2f size, std::string texture_file_name_default, std::function<void()>action)
    :onClickFunction(action)
{
    // TEKSTURA
    shape.setSize(size);
    shape.setPosition(position);
    // shape.setFillColor(defaultColor); // Kolor awaryjny, gdyby tekstura si� nie za�adowa�a
    shape.setFillColor(sf::Color::White); // Ustawienie jednolitego t�a, aby unikn�� przenikania
    // �adowanie tekstury
    if (!tex.loadFromFile(texture_file_name_default) and texture_file_name_default != "") {
        std::cerr << "Nie mo�na za�adowa� tekstury: " << texture_file_name_default << std::endl;
    }
    else if (texture_file_name_default == "") {
        shape.setTexture(nullptr);
    }
    else {
        shape.setTexture(&tex);
    }

    /////HOVER
    hover.setSize(size);
    hover.setPosition(position);
    hover.setFillColor(sf::Color(255, 255, 255, 0)); // Domy�lnie przezroczysty
}


Button::Button(const std::string& label, sf::Vector2f position, sf::Vector2f size, std::string texture_file_name_default)
{
    // TEKSTURA
    shape.setSize(size);
    shape.setPosition(position);
    // shape.setFillColor(defaultColor); // Kolor awaryjny, gdyby tekstura si� nie za�adowa�a
    shape.setFillColor(sf::Color::White); // Ustawienie jednolitego t�a, aby unikn�� przenikania
    // �adowanie tekstury
    if (!tex.loadFromFile(texture_file_name_default) and texture_file_name_default != "") {
        std::cerr << "Nie mo�na za�adowa� tekstury: " << texture_file_name_default << std::endl;
    }
    else if (texture_file_name_default == "") {
        shape.setTexture(nullptr);
    }
    else {
        shape.setTexture(&tex);
    }
    //setText(label);
    /////HOVER
    hover.setSize(size);
    hover.setPosition(position);
    hover.setFillColor(sf::Color(255, 255, 255, 0)); // Domy�lnie przezroczysty
}


void Button::setText(const std::string& label) {
    text.setString(label);
}

void Button::setPosition(sf::Vector2f position) {
    shape.setPosition(position);
    text.setPosition(position.x + 10, position.y + 10);
}

void Button::setSize(sf::Vector2f size) {
    shape.setSize(size);
}

void Button::setColor(sf::Color color) {
    defaultColor = color;
    shape.setFillColor(defaultColor);
}

void Button::setHover(sf::Color hover) {
    hoverColor = hover;
}

void Button::setFont()
{
    if (!font.loadFromFile("kobani.ttf")) {
        std::cout << "Nie mo�na za�adowa� czcionki!" << std::endl;
    }
    this->font = font;
}

void Button::setTex(std::string texture_file_name)
{

    if (!this->tex.loadFromFile(texture_file_name)) {
        std::cout << "Nie mo�na za�adowa� tekstury: " << texture_file_name << std::endl;
    }

}




void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(hover);
    window.draw(text);
}

void Button::handleEvents(sf::Vector2i mouse_pos, sf::Event event)
{
    if (this->isClicked(mouse_pos, event)) {
        if (onClickFunction) {
            onClickFunction();
        }
    }
    if (this->isHovered(mouse_pos)) {
        hover.setFillColor(sf::Color(255, 255, 255, 40));
        hover.setPosition(this->shape.getPosition());
    }
    else {
        hover.setFillColor(sf::Color(255, 255, 255, 0));
    }

}

bool Button::isHovered(sf::Vector2i mousePos) {
    sf::FloatRect bounds = shape.getGlobalBounds();
    bool isHover = bounds.contains(static_cast<sf::Vector2f>(mousePos));

    return isHover;
    /*
        if (shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            hover.setFillColor(sf::Color(255, 255, 255, 40)); // Lekko bia�a nak�adka (przezroczysto�� = 100)
            return true;
        }
        else {
            hover.setFillColor(sf::Color(255, 255, 255, 0)); // Lekko bia�a nak�adka (przezroczysto�� = 100)
            return false;
        }
        */
}

bool Button::isClicked(sf::Vector2i mousePos, sf::Event event) {
    return isHovered(mousePos) && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left;
}

sf::Texture Button::getTex()
{
    return this->tex;
}

sf::Vector2f Button::getPosition()
{
    return this->shape.getPosition();
}







//////////////////ITEMSLOT



ItemSlot::ItemSlot(sf::Vector2f position, sf::Vector2f size, ItemType item_type, std::string texture_file_name_default, std::function<void()>action, Item* curr_item) :
    Button(), allowed_item_type(item_type)
{

    isItemDragged = false;
    isDragSource = false;
    this->setItem(curr_item);
    this->onClickFunction = action;
    setItem(current_item);
    setPosition(position);
    setSize(size);
    if (!tex.loadFromFile(texture_file_name_default) and texture_file_name_default != "") {
        std::cerr << "Nie mo�na za�adowa� tekstury: " << texture_file_name_default << std::endl;
    }
    else if (texture_file_name_default == "") {
        shape.setTexture(nullptr);
    }
    else {
        shape.setTexture(&tex);
    }
   // if (current_item != nullptr) {
     //   this->current_item->sprite.setTexture(current_item->texture);
       // this->current_item->sprite.setScale(0.5f, 0.5f);
        //this->current_item->setPosition(position);
    //}

}

void ItemSlot::setItem(Item* item)
{
    //nowy item to trzeba go ustawic w dobrym miejscu
  
    this->current_item = item;
    if (item) {
        this->current_item->setPosition(this->getPosition());
        this->current_item->sprite.setTexture(current_item->texture);
        this->current_item->sprite.setScale(0.5f, 0.5f);
    }
   
    
    
    //std::cout<<"NOWY itemek dadadadadd" << this->current_item->getGlobalBounds().getPosition().x;
    //dodac sprawdzanie czy pasuje typ itemu

}

Item* ItemSlot::getCurrentItem()
{
    return current_item;
}
// ItemSlot.h, w public:
    /// Zwraca prostokątny obszar slotu (do testów hover / drop)


bool ItemSlot::getIsItemDragged()
{
    return isItemDragged;
}

void ItemSlot::setIsItemDragged(bool dragging)
{
    isItemDragged = dragging;
}

void ItemSlot::moveItem(sf::Vector2f& diff)
{
    // jeżeli jest jakiś item i wciśnięty jest lewy przycisk myszy
    if (current_item) {
        current_item->sprite.move(diff);
        std::cout << "Moved item by x:" << diff.x << " y:" << diff.y << std::endl;
    }
}

sf::FloatRect ItemSlot::getGlobalBounds() const
{
    return shape.getGlobalBounds();
}

void ItemSlot::draw(sf::RenderWindow& window)
{
    window.draw(shape);
    window.draw(hover);

    if (this->current_item != nullptr) {
        //   if (current_item->isNewPosition()) {
        
  //      this->current_item->sprite.setScale(0.5f, 0.5f);
    //    this->current_item->setPosition(this->getPosition());

      //  this->current_item->sprite.setTexture(current_item->texture);
        // }
        window.draw(this->current_item->sprite);
        window.draw(hover);
        //  this->current_item->sprite.setColor(sf::Color::Yellow);

    }
}
void ItemSlot::tryStartDrag(const sf::Vector2i& mousePos, const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left)
    {
        Item* item = getCurrentItem();
        if (!isDragSource && item &&
            item->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
        {
            isDragSource = true;
            isItemDragged = true;
            last_mouse_pos = mousePos;
            std::cout << "Start drag item " << item->getId() << std::endl;
        }
    }
}

void ItemSlot::tryEndDrag(const sf::Vector2i& mousePos, const sf::Event& event, ItemSlot*source) {

    if (event.type == sf::Event::MouseButtonReleased &&
        event.mouseButton.button == sf::Mouse::Left &&
        source && source->isDragSource && source->isItemDragged)
    {
        if (shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            Item* temp = current_item;
            setItem(source->getCurrentItem());
            source->setItem(temp);
            std::cout << "Swapped items between slots" << std::endl;
        }
        source->isItemDragged = false;
        source->isDragSource = false;
    }
}

void ItemSlot::handleEvents(sf::Vector2i mouse_pos, sf::Event event){
if (!isItemDragged) {
    // hover effect when not dragging
    if (shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mouse_pos))) {
        hover.setFillColor(sf::Color(255, 255, 255, 40));
        hover.setPosition(shape.getPosition());
    }
    else {
        hover.setFillColor(sf::Color(255, 255, 255, 0));
    }
}
else {
    // while dragging, move the sprite
    sf::Vector2i delta = mouse_pos - last_mouse_pos;
    sf::Vector2f diff(static_cast<float>(delta.x), static_cast<float>(delta.y));
    moveItem(diff);
}
last_mouse_pos = mouse_pos;

}