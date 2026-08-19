#include <dialoguetree.h>

uint32_t DialogueTree::addNode(DialogueNode::NodeType type) 
{
	uint32_t new_ID = m_IDGenerator.generateID();

	switch (type)
	{
		case DialogueNode::NodeType::Speaker:
			m_nodeMap[new_ID] = std::make_unique<SpeakerNode>(new_ID);
			break;

		case DialogueNode::NodeType::Choice:
			m_nodeMap[new_ID] = std::make_unique<ChoiceNode>(new_ID);
			break;
	}

	// Check if this should be default entry point.
	if (m_nodeMap.size() == 1)
	{
		std::cout << "[TREE] First node added, setting as default entry point" << std::endl;
		m_entryPoint = m_nodeMap[new_ID].get();
	}

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