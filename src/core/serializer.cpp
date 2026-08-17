#include <serializer.h>

void Serializer::serialize(const DialogueTree& dialogueTree)
{
	std::cout << "Size of tree: " << sizeof(dialogueTree) << std::endl;
	std::cout << "Number of nodes: " << dialogueTree.getSize() << std::endl;
	// Serialize scene name
	// Serialize all dialogue nodes
		// Serialize all dialogue choices
	// Serialize entry node
}