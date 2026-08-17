#pragma once

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
	 * @brief Base struct for all dialogue node types.
	 */
	struct DialogueNode {
		uint32_t nodeID;
		DialogueNode(uint32_t newID) : nodeID(newID) {}
		virtual ~DialogueNode() = default;
	};

	/**
	 * @brief Structure for representing a speaker node.
	 * 
	 * Contains exactly one output.
	 */
	struct SpeakerNode : DialogueNode {
		std::string speakerText;
		uint32_t followingNodeID;
	};

	/**
	 * @brief Representation of a single dialogue choice.
	 */
	struct DialogueChoice {
		std::string choiceText;
		uint32_t resultingNodeID;
	};

	/**
	* @brief Structure for representing a choice node.
	*/
	struct ChoiceNode : DialogueNode {
		std::vector<DialogueChoice> choices;
	};

	/**
	 * @brief Map for representing a flat dialogue tree.
	 * 
	 * Uses unique_ptr to declare ownership over each node.
	 */
	std::unordered_map<std::uint32_t, std::unique_ptr<DialogueNode>> m_nodeMap;
	IDGenerator m_IDGenerator;


public:
	enum class NodeType {
		Speaker,
		Choice
	};

	/**
	* @return Pointer to DialogueNode instance containing nodeID.
	* 
	* Returns nullptr if no node exists with nodeID.
	*/
	DialogueNode* const getNode(uint32_t nodeID);

	/**
	 * @brief Adds a new typed node to this tree.
	 * @param type Specified type of node.
	 * @return The ID of the added node.
	 */
	uint32_t addNode(NodeType type);

	// Removes node with specified ID.
	void removeNode(uint32_t nodeID);

	// Removes all nodes from tree.
	void clearTree();

	// Appends choice to DialogueNode with specified ID.
	void addChoice(uint32_t nodeID);

	// Deletes choice from specified DialogueNode at given index.
	bool deleteChoice(uint32_t nodeID, int choiceIndex);

	// Returns the ID of this tree's entry node.
	int getFirstNodeID() const;

	// Returns number of nodes in this tree.
	int getSize() const;
};