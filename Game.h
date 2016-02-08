#pragma once
#include <SFML/Graphics.hpp>

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

	sf::RenderWindow m_window;
	sf::CircleShape m_player;
};

