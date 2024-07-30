#include <SFML/Graphics.hpp>

#include "Control.h"
#include "Player.h"
#include "GameMap.h"


bool checkCollision(sf::Sprite& obj1, sf::Sprite& obj2) {
    auto boundingBox1 = obj1.getGlobalBounds();
    auto boundingBox2 = obj2.getGlobalBounds();

    return boundingBox1.intersects(boundingBox2);
}

void handleCollision(sf::Sprite& obj1, sf::Sprite& obj2) {
    if (checkCollision(obj1, obj2)) {
        obj1.setColor(sf::Color::Red);
        obj2.setColor(sf::Color::Red);
    }
    else {
        obj1.setColor(sf::Color::White);
        obj2.setColor(sf::Color::White);
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML works!");
    GameMap* map = new GameMap(
        "assets/SBS - Tiny Texture Pack 2 - 512x512/512x512/Elements/Elements_20-512x512.png",
        "assets/SBS - Tiny Texture Pack 2 - 512x512/512x512/Brick/Brick_20-512x512.png",
        MapType::BoxBoundary,
        window);
    Control* controller = new Control;
    Player* player = new Player(
        "./assets/player.png", 
        sf::Vector2f{window.getSize().x / 2.0f, window.getSize().y / 2.0f },
        0.0f,
        sf::Vector2f{1.0f, 1.0f});


    auto windowSize = window.getSize();





    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)  window.close();
            //Use escape to exit
            controller->handleControl(window);


            if (event.type == sf::Event::Resized) {

                sf::Vector2f scaleRate{
                    windowSize.x / static_cast<float>(window.getSize().x),
                    windowSize.y / static_cast<float>(window.getSize().y),
                };
                windowSize = window.getSize();

                //Save scale awoiding stretching
                map->resize(scaleRate);
                player->resize(scaleRate);

#ifdef _DEBUG
                std::cout << "windowSize: " << windowSize.x << ", " << windowSize.y << std::endl;
#endif
            };
        }
        
        controller->handleControl(player, *map);
        //handleCollision(player, box);




        window.clear(sf::Color{0, 230, 0});
        map->draw(window);
        window.draw(player->sprite);
        window.display();
    }

    return 0;
}