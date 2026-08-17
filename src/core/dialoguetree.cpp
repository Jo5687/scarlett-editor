#include <dialoguetree.h>

DialogueTree::DialogueNode* const DialogueTree::getNode(uint32_t nodeID)
{
	auto result = m_nodeMap.find(nodeID);

	// If the entry exists, return a raw pointer to the node.
	if (result != m_nodeMap.end())
	{
		return result->second.get();
	}

	return nullptr;
}

uint32_t DialogueTree::addNode(DialogueTree::NodeType type) 
{
	uint32_t new_ID = m_IDGenerator.generateID();

	m_nodeMap[new_ID] = std::make_unique<DialogueNode>(new_ID);

	std::cout << "Adding new dialogue node " << new_ID << std::endl;
	return new_ID;
}

int DialogueTree::getSize() const
{
	return m_nodeMap.size();
}