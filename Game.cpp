#include "Game.h"
#include "World.h"
#include <iostream>

Game::Game()
{
	m_window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "SFML Application", sf::Style::Close);
	m_world = new World(m_window);

	m_screenSize.x = m_window->getSize().x;
	m_screenSize.y = m_window->getSize().y;
}

Game::~Game()
{
	delete m_world;
	delete m_window;
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (m_window->isOpen())
	{
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}

void Game::processEvents()
{
	CommandQueue* commands = &m_world->getCommandQueue();

	sf::Event ev;
	while (m_window->pollEvent(ev))
	{
		m_player.handleEvent(ev, *commands);

		if (ev.type == sf::Event::Closed)
			m_window->close();
	}

	m_player.handleRealtimeInput(*commands);
}

void Game::update(sf::Time delta)
{
	m_world->update(delta);
}

void Game::render()
{
	m_window->clear();
	m_world->draw();
	m_window->setView(m_window->getDefaultView());
	m_window->display();
}