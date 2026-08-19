#pragma once

#include <memory>
#include <iostream>
#include <string>

class DialogueNode
{
protected:
	uint32_t m_ID;

public:
	DialogueNode(uint32_t ID) : m_ID(ID) {}
	virtual ~DialogueNode() {}

	enum class NodeType {
		Speaker,
		Choice
	};

	uint32_t getID() const { return m_ID; }
	virtual NodeType getType() const = 0;
};