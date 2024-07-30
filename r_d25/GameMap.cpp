#include <algorithm>

#include "GameMap.h"

GameMap::GameMap(
	std::string pathToAllowedTexture, 
	std::string pathToBlockTexture, 
	MapType type,
	sf::RenderWindow& window
	)
{

	allowedTexture.loadFromFile(pathToAllowedTexture);
	allowedTexture.setRepeated(false);


	blockedTexture.loadFromFile(pathToBlockTexture);
	blockedTexture.setRepeated(false);
	
	auto w_size = window.getSize();
	auto w_center_pos = sf::Vector2f{ w_size.x / 2.0f, w_size.y / 2.0f};

	switch (type)
	{
	case MapType::BoxBoundary: {
		sf::Sprite field;
		field.setTexture(allowedTexture);
		field.setPosition(w_center_pos);
		field.setOrigin(w_center_pos);
	

		auto f_bounds = field.getGlobalBounds().getSize();
		sf::Vector2f scalerate = sf::Vector2f{ w_size.x / f_bounds.x, w_size.y / f_bounds.y };

		field.setScale(scalerate);
		allowedSprites.push_back(field);

		sf::Sprite leftBlock;
		sf::Sprite rightBlock;
		sf::Sprite topBlock;
		sf::Sprite bottomBlock;

		auto block_size = blockedTexture.getSize();
		setBlock(leftBlock, blockedTexture,
			sf::Vector2f{ borderSize / 2.0f, w_size.y / 2.0f },
			sf::Vector2f{ borderSize / static_cast<float>(block_size.x), static_cast<float>(w_size.y) / static_cast<float>(block_size.y)}
		);

		setBlock(rightBlock, blockedTexture,
			sf::Vector2f{ w_size.x - (borderSize / 2.0f), w_size.y / 2.0f },
			sf::Vector2f{ borderSize / static_cast<float>(block_size.x), static_cast<float>(w_size.y) / static_cast<float>(block_size.y) }
		);

		setBlock(topBlock, blockedTexture,
			sf::Vector2f{ w_size.x / 2.0f, borderSize / 2.0f },
			sf::Vector2f{ w_size.x / static_cast<float>(block_size.x), borderSize / static_cast<float>(block_size.y) }
		);

		setBlock(bottomBlock, blockedTexture,
			sf::Vector2f{ w_size.x / 2.0f, w_size.y - (borderSize / 2.0f)},
			sf::Vector2f{ w_size.x / static_cast<float>(block_size.x), borderSize / static_cast<float>(block_size.y) }
		);
		break;
	}
	case MapType::CircleBoundary: {
		//TODO
		break;
	}
	default:
		break;
	}
}

void GameMap::setBlock(sf::Sprite& sprite, sf::Texture& texture, sf::Vector2f position, sf::Vector2f scale)
{
	sprite.setTexture(texture);
	sprite.setPosition(position);
	sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);
	sprite.setScale(scale);

	blockSprites.push_back(sprite);
}

void GameMap::draw(sf::RenderWindow& window)
{
	std::for_each(allowedSprites.begin(), allowedSprites.end(), 
		[&window](sf::Sprite& sprite) {

#ifdef _MAP_DEBUG
			auto position = sprite.getPosition();
			std::cout << "Position " << position.x << ", " << position.y << std::endl;
#endif


			window.draw(sprite); 
		}
		);

	std::for_each(blockSprites.begin(), blockSprites.end(),
		[&window](sf::Sprite& sprite) {

#ifdef _MAP_DEBUG
			auto position = sprite.getPosition();
			std::cout << "Position: " << position.x << ", " << position.y << std::endl;
#endif
			
			window.draw(sprite); 
		}
	);
}

void GameMap::resize(sf::Vector2f dScale)
{
	std::for_each(blockSprites.begin(), blockSprites.end(),
		[&dScale](sf::Sprite& sprite) {
			auto scale = sprite.getScale();

			sprite.setScale(
				scale.x * dScale.x,
				scale.y * dScale.y
			);
		}
	);
}

bool GameMap::checkCollision(sf::FloatRect rect)
{
	auto it = std::find_if(blockSprites.begin(), blockSprites.end(),
		[&rect](const sf::Sprite& sprite) {
			return rect.intersects(sprite.getGlobalBounds());
		}
	);

	if (it == blockSprites.end()) {
		return false;
	}

	return true;
}
