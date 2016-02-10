#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include <vector>
#include <functional>
#include <queue>

#include "Command.h"

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
	typedef std::unique_ptr<SceneNode> SceneNodePtr;

	SceneNode();
	void attachChild(SceneNodePtr child);
	SceneNodePtr detachChild(const SceneNode& node);
	void update(sf::Time dt);

	sf::Transform getWorldTransform() const;
	sf::Vector2f getWorldPosition() const;

	virtual unsigned int getCategory() const;
	void onCommand(const Command& command, sf::Time dt);

private:
	virtual void updateCurrent(sf::Time dt);
	void updateChildren(sf::Time dt);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

	std::vector<SceneNodePtr> m_children;
	SceneNode* m_parent;
};

