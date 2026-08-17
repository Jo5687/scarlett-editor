#pragma once

#include <dialoguetree.h>
#include <iostream>

class Serializer
{
public:
	/**
	 * @brief 
	 * @param dialogueTree Read-only reference to a DialogueTree instance. 
	 */
	static void serialize(const DialogueTree& dialogueTree);
};