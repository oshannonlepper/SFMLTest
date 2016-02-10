#include "Ship.h"
#include "ResourceManager.hpp"

#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>


Textures::ID toTextureID(Ship::ShipType type) {
	switch (type) {
	case Ship::Player:
		return Textures::Player;
	}
	return Textures::Player;
}

Ship::Ship(ShipType type, const TextureManager& textures)
	: m_characterType(type)
	, m_sprite(textures.get(toTextureID(type)))
{
	sf::FloatRect bounds = m_sprite.getLocalBounds();
	m_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Ship::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}

void Ship::accelerate(sf::Vector2f vel)
{
	setVelocity(getVelocity() + vel);
}