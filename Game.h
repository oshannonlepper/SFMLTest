#pragma once

#include "ResourceIdentifiers.h"
#include "World.h"
#include "Player.h"
#include <SFML/Graphics.hpp>




class Game
{
public:
	Game();
	~Game();

	void run();

	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
private:
	void processEvents();
	void update(sf::Time delta);
	void render();

	bool m_isMovingRight;
	bool m_isMovingUp;
	bool m_isMovingLeft;
	bool m_isMovingDown;

	//TextureManager m_textureManager;
	World* m_world;
	sf::RenderWindow* m_window;
	sf::Texture m_texture;
	Player m_player;
	sf::Vector2f m_screenSize;
};

