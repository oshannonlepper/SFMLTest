#pragma once
#include "SceneNode.h"
#include <SFML\Graphics.hpp>

class Entity : public SceneNode
{
public:
	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity() const;
private:
	virtual void updateCurrent(sf::Time dt);
	sf::Vector2f m_velocity;
};

