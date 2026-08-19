#pragma once

#include <core/tree/dialoguenode.h>
#include <core/tree/speakernode.h>
#include <core/tree/choicenode.h>

#include <string>
#include <unordered_map>
#include <vector>
#include <idgenerator.h>
#include <memory>
#include <iostream>

/**
* @brief Flat data structure representing a directed graph of dialogue nodes and their nested choices.
* 
* This class exposes an interface for maniuplating the data structure, as well as containing the structure
* itself.
*/
class DialogueTree
{
private:
	/**
	 * @brief Map for representing a flat dialogue tree.
	 * 
	 * Uses unique_ptr to declare ownership over each node.
	 */
	std::unordered_map<std::uint32_t, std::unique_ptr<DialogueNode>> m_nodeMap;
	IDGenerator m_IDGenerator;
	DialogueNode* m_entryPoint;


public:
	~DialogueTree() { std::cout << "[TREE] Deleting tree " << std::endl; }
	/**
	 * @brief Adds a new typed node to this tree.
	 * @param type Specified type of node.
	 * @return The ID of the added node.
	 */
	uint32_t addNode(DialogueNode::NodeType type);

	// Removes node with specified ID.
	void removeNode(uint32_t nodeID);

	/**
	* @return Pointer to DialogueNode instance containing nodeID.
	*
	* Returns nullptr if no node exists with nodeID.
	*/
	DialogueNode* const getNode(uint32_t nodeID);
	DialogueNode* const getEntryNode() { return m_entryPoint; }

	// Removes all nodes from tree.
	void clearTree() { m_nodeMap.clear(); }

	// Returns number of nodes in this tree.
	int getSize() const;
};