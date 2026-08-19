#include <dialoguetree.h>

uint32_t DialogueTree::addNode(DialogueNode::NodeType type) 
{
	uint32_t new_ID = m_IDGenerator.generateID();

	m_nodeMap[new_ID] = std::make_unique<DialogueNode>(new_ID);

	return new_ID;
}

void DialogueTree::removeNode(uint32_t nodeID)
{
	m_IDGenerator.returnID(nodeID);
	m_nodeMap.erase(nodeID);
}

DialogueNode* const DialogueTree::getNode(uint32_t nodeID)
{
	auto result = m_nodeMap.find(nodeID);

	// If the entry exists, return a raw pointer to the node.
	if (result != m_nodeMap.end())
	{
		return result->second.get();
	}

	return nullptr;
}

int DialogueTree::getSize() const
{
	return m_nodeMap.size();
}