#pragma once
#include <SFML/Graphics.hpp>
#include "CommandQueue.h"

class Player
{
public:

	enum Action
	{
		MoveLeft,
		MoveRight,
		MoveUp,
		MoveDown,
		ActionCount
	};

	Player();

	void				handleEvent(const sf::Event& event, CommandQueue& commands);
	void				handleRealtimeInput(CommandQueue& commands);

	void				assignKey(Action action, sf::Keyboard::Key key);
	sf::Keyboard::Key	getAssignedKey(Action action) const;

private:
	void			initializeActions();
	static bool		isRealtimeAction(Action action);

	std::map<sf::Keyboard::Key, Action>		m_keyBinding;
	std::map<Action, Command>				m_actionBinding;
};

