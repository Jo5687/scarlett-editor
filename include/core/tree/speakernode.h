#pragma once

#include <core/tree/dialoguenode.h>
#include <vector>

class SpeakerNode : public DialogueNode
{
protected:
	std::string m_speakerText{};
	uint32_t m_followingNodeID{};

public:
	SpeakerNode(uint32_t nodeID) : DialogueNode(nodeID) { std::cout << "[SPEAKER] Creating node " << m_ID << std::endl; }
	~SpeakerNode() { std::cout << "[SPEAKER] Deleting node " << m_ID << std::endl; }

	void setText(const std::string& text) { m_speakerText = text; }

	DialogueNode::NodeType getType() const { return DialogueNode::NodeType::Speaker; }
	uint32_t getFollowingNodeID() { return m_followingNodeID; }
};