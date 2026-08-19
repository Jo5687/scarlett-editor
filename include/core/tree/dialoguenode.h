#pragma once

#include <memory>
#include <iostream>

class DialogueNode
{
private:
	uint32_t m_ID;

public:
	DialogueNode(uint32_t ID) : m_ID(ID) { std::cout << "[NODE] Adding node " << m_ID << std::endl; };
	~DialogueNode() { std::cout << "[NODE] Deleting node " << m_ID << std::endl; }

	enum class NodeType {
		Speaker,
		Choice
	};

	uint32_t getID() const;
	NodeType getType() const;
};