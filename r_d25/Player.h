#pragma once

#include <SFML/Graphics.hpp>

#include "GameMap.h"



class Player
{
public:
	Player(std::string pathToTexture, sf::Vector2f startPosition, float startRotation, sf::Vector2f startScale);

	void move(sf::Vector2f dPosition, GameMap& map );
	void rotate(float dRotation, GameMap& map);
	void scale(sf::Vector2f dScale, GameMap& map);

	void resize(sf::Vector2f dScale);

	sf::Sprite sprite;
	sf::Texture texture;

private:
	float positionSpeed = 0.5f;
	float scaleSpeed = 0.01f;
	float rotationSpeed = 0.1f;
};