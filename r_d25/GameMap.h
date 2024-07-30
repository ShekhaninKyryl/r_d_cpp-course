#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

enum class MapType
{
	BoxBoundary,
	CircleBoundary,
};

enum class BlockMopvement
{
	BlockLeft,
	BlockRight,
	BlockTop,
	BlockBottom,
};

class GameMap
{
public:
	GameMap(
		std::string pathToAllowedTexture,
		std::string pathToBlockTexture,
		MapType type, 
		sf::RenderWindow& window
		);

	void draw(sf::RenderWindow& window);
	void resize(sf::Vector2f dScale);

	bool checkCollision(sf::FloatRect rect);

private:

	void setBlock(sf::Sprite& sprite, sf::Texture& texture, sf::Vector2f position, sf::Vector2f scale);

	std::vector<sf::Sprite> blockSprites;
	std::vector<sf::Sprite> allowedSprites;

	sf::Texture allowedTexture;
	sf::Texture blockedTexture;

	float borderSize = 100.0f;
};