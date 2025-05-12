// w tym miejscu nawiasy ostre (youtube uniemożliwia umieszczenie ich w opisie filmu)
/*
TODO
- wycentrowac tekst w przyciskach i zmienic jego kolor



*/
#include "Game.h"

int main() {
    //setup
    Game game;


    //game loop
    while (game.running()) {
        //Update
        game.update();
        
        ///Render
        game.render();
    }
    //end of aplication
    
    return 0;
}



/*
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Przezroczysta grafika w SFML");

    sf::Texture texture;
    if (!texture.loadFromFile("customksztalt.png")) {  // Upewnij się, że ścieżka do pliku jest poprawna
        std::cerr << "Błąd wczytywania pliku!" << std::endl;
        return -1;
    }

    // Ustawienie filtra wygładzania (opcjonalne)
    texture.setSmooth(true);

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(200, 150);  // Ustawienie pozycji

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Cyan);  // Ustawienie koloru tła (widoczny za przezroczystością)
        window.draw(sprite);
        window.display();
    }

    return 0;
}*/