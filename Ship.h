#pragma once
#include "Entity.h"
#include "ResourceIdentifiers.h"
#include <SFML/Graphics/Sprite.hpp>

class Ship : public Entity
{
public:
	enum ShipType {
		Player,
		Enemy
	};

	Ship(ShipType type, const TextureManager& textures);
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	void accelerate(sf::Vector2f vel);
private:
	sf::Sprite m_sprite;
	ShipType m_characterType;
};

