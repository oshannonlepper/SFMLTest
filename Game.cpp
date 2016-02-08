#include "Game.h"



Game::Game() : m_window(sf::VideoMode(800, 600), "SFML Application"), m_player() {
	m_player.setRadius(40.f);
	m_player.setPosition(100.f, 100.f);
	m_player.setFillColor(sf::Color::Cyan);
}

Game::~Game() {
}

void Game::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (m_window.isOpen()) {
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
	if (key == sf::Keyboard::W)
		m_isMovingUp = isPressed;
	if (key == sf::Keyboard::A)
		m_isMovingLeft = isPressed;
	if (key == sf::Keyboard::S)
		m_isMovingDown = isPressed;
	if (key == sf::Keyboard::D)
		m_isMovingRight = isPressed;
}

void Game::processEvents() {
	sf::Event ev;
	while (m_window.pollEvent(ev)) {
		switch (ev.type) {
		case sf::Event::KeyPressed:
			handlePlayerInput(ev.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(ev.key.code, false);
			break;
		case sf::Event::Closed:
			m_window.close();
			break;
		}
	}
}

void Game::update(sf::Time delta) {
	sf::Vector2f movement(0.f, 0.f);
	if (m_isMovingDown)
		movement.y += PlayerSpeed;
	if (m_isMovingUp)
		movement.y -= PlayerSpeed;
	if (m_isMovingRight)
		movement.x += PlayerSpeed;
	if (m_isMovingLeft)
		movement.x -= PlayerSpeed;
	m_player.move(movement*delta.asSeconds());
}

void Game::render() {
	m_window.clear();
	m_window.draw(m_player);
	m_window.display();
}