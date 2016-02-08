#pragma once

#include "ResourceManager.h"
#include <SFML/Graphics.hpp>

namespace Textures {
	enum ID { Player };
};

typedef ResourceManager<sf::Texture, Textures::ID> TextureManager;

class Game
{
public:
	Game();
	~Game();
	void run();

	const float PlayerSpeed = 400.f;
	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
private:
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void processEvents();
	void update(sf::Time delta);
	void render();

	bool m_isMovingRight;
	bool m_isMovingUp;
	bool m_isMovingLeft;
	bool m_isMovingDown;

	TextureManager m_textureManager;
	sf::RenderWindow m_window;
	sf::Texture m_texture;
	sf::Sprite m_player;
};

