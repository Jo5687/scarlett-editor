#include <iostream>
#include <QApplication>
#include <mainwindow.h>
#include <serializer.h>

// Creates and serializes a temporary tree
void test_node_creation()
{
	DialogueTree tree;

	tree.addNode(DialogueNode::NodeType::Speaker);
	tree.addNode(DialogueNode::NodeType::Choice);

	auto* node = tree.getNode(1);

	if (auto* choiceNode = dynamic_cast<ChoiceNode*>(node))
	{
		choiceNode->addChoice();
		std::cout << "[TEST] This is a choice node" << std::endl;
	}

	Serializer::serialize(tree);

	tree.clearTree();
}

int main(int argc, char* argv[]) 
{
	QApplication app(argc, argv);

	MainWindow* window = new MainWindow();
	window->show();

	test_node_creation();
	
	// TODO: Force visual tree to refresh for loaded test nodes.

	app.exec();

	return 0;
}