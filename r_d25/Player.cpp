#include <iostream>


#include "Player.h"

Player::Player(
	std::string pathToTexture, 
	sf::Vector2f startPosition = sf::Vector2f{ 0.0f, 0.0f },
	float startRotation = 0.0f, 
	sf::Vector2f startScale = sf::Vector2f{1.0f, 1.0f})
{
	this->texture.loadFromFile(pathToTexture);
	this->sprite.setTexture(this->texture);
	

	this->sprite.setPosition(startPosition);
	//this->sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);
	this->sprite.setRotation(startRotation);
	this->sprite.setScale(startScale);
}

void Player::move(sf::Vector2f dPosition, GameMap& map)
{
	auto position = sprite.getPosition();
	auto rect = sprite.getGlobalBounds();


	float newXPosition = position.x + (dPosition.x * positionSpeed);
	float newYPosition = position.y + (dPosition.y * positionSpeed);

	sf::Vector2f newPosition{ newXPosition, newYPosition };
	if (map.checkCollision(sf::FloatRect{newXPosition, rect.top, rect.width, rect.height})) {
		newPosition.x = position.x;
	}

	if (map.checkCollision(sf::FloatRect{ rect.left, newYPosition, rect.width, rect.height })) {
		newPosition.y = position.y;
	}

	sprite.setPosition(newPosition);

#ifdef _DEBUG
	auto d_position = sprite.getPosition();
	std::cout << "Position: " << d_position.x  << ", " << d_position.y << std::endl;
#endif
}

void Player::rotate(float dRotation, GameMap& map)
{
	auto rotation = sprite.getRotation();
	sprite.setRotation(rotation + (dRotation * rotationSpeed));

#ifdef _DEBUG
	auto d_rotation = sprite.getRotation();
	std::cout << "Rotation: " << d_rotation << std::endl;
#endif
}

void Player::scale(sf::Vector2f dScale, GameMap& map)
{
	auto scale = sprite.getScale();
	auto rect = sprite.getGlobalBounds();
	auto newScale = scale + (dScale * scaleSpeed);


	//Todo fix scale collision
	if (map.checkCollision(sf::FloatRect{ rect.left, rect.top, rect.width * dScale.x * scaleSpeed, rect.height * dScale.y * scaleSpeed })) {
		sprite.setScale(
			scale.x,
			scale.y
		);
	}
	else {
		// Set old scale value if new scale is reverse
		sprite.setScale(
			newScale.x < 1.0f ? scale.x : newScale.x,
			newScale.y < 1.0f ? scale.y : newScale.y
		);
	}


#ifdef _DEBUG
	auto d_scale = sprite.getScale();
	std::cout << "Scale: " << d_scale.x << ", " << d_scale.y << std::endl;
#endif

}

void Player::resize(sf::Vector2f dScale)
{
	auto scale = sprite.getScale();

	sprite.setScale(
		scale.x * dScale.x,
		scale.y * dScale.y
	);
}


