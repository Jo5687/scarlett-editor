#pragma once

#include <core/tree/dialoguenode.h>
#include <vector>

class ChoiceNode : public DialogueNode
{
protected:
	struct Choice
	{
		std::string choiceText;
		uint32_t resultingNodeID;
	};

	std::vector<std::unique_ptr<Choice>> choices;

public:
	ChoiceNode(uint32_t nodeID) : DialogueNode(nodeID) { std::cout << "[CHOICE] Creating node " << m_ID << std::endl; }
	~ChoiceNode() { std::cout << "[CHOICE] Deleting node " << m_ID << std::endl; }

	DialogueNode::NodeType getType() const { return DialogueNode::NodeType::Choice; }

	void addChoice() { choices.push_back(std::make_unique<Choice>()); }

	void editChoiceText(std::string text, int index);
	void editChoiceID(uint32_t ID, int index);

	void removeChoice(int index);
	void removeAllChoices();
};