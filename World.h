#pragma once
#include <array>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "ResourceManager.hpp"
#include "ResourceIdentifiers.h"
#include "SpriteNode.h"
#include "SceneNode.h"
#include "Ship.h"
#include "CommandQueue.h"

class World : private sf::NonCopyable
{
public:
	World(sf::RenderWindow* window);
	void update(sf::Time dt);
	void draw();

	CommandQueue& getCommandQueue();

	const float PlayerSpeed = 400.f;
private:
	void loadTextures();
	void buildScene();

	enum Layer {
		Background,
		Air,
		LayerCount
	};

	sf::RenderWindow*					m_window;
	sf::View							m_worldView;
	TextureManager						m_textures;

	SceneNode							m_sceneGraph;
	std::array<SceneNode*, LayerCount>	m_sceneLayers;

	sf::FloatRect						m_worldBounds;
	sf::Vector2f						m_spawnPosition;
	float								m_scrollSpeed;
	Ship*								m_playerShip;
	CommandQueue						m_commandQueue;
};

