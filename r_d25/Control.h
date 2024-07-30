#pragma once

#include "Player.h"
#include "GameMap.h"

class Control
{
public:

	void handleControl(Player* player, GameMap& map) {

        sf::Vector2f c_position = sf::Vector2f{ 0.0f, 0.0f };
        float c_rotation = 0.0f;
        sf::Vector2f c_scale = sf::Vector2f{ 0.0f, 0.0f };


        //Movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            c_position.y = -1.0f;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            c_position.y = 1.0f;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            c_position.x = 1.0f;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            c_position.x = -1.0f;
        }

        //Rotation
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            c_rotation = 1.0f;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            c_rotation = -1.0f;
        }

        const float scaleSpeed = 0.01f;

        float scale = 0;

        //Scale
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
            c_scale = sf::Vector2f{ 1.0f, 1.0f };
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
            c_scale = sf::Vector2f{ -1.0f, -1.0f };
        }

        if (c_position != sf::Vector2f{ 0.0f, 0.0f }) { player->move(c_position, map); }
        if (c_rotation != 0.0f) { player->rotate(c_rotation, map); }
        if (c_scale != sf::Vector2f{ 0.0f, 0.0f }) { player->scale(c_scale, map); }
	}
    void handleControl(sf::RenderWindow& window) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)) {
            window.setSize(sf::Vector2u(800, 600));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) {
            window.setSize(sf::Vector2u(1024, 768));
        }

    }

};