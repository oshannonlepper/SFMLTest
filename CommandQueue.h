#pragma once
#include "SceneNode.h"

class CommandQueue
{
public:
	void		push(const Command& command);
	Command		pop();
	bool		isEmpty();
private:
	std::queue<Command> m_queue;
};
