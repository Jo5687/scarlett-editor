#include <iostream>
#include <QApplication>
#include <mainwindow.h>
#include <serializer.h>

void test_node_creation()
{
	DialogueTree tree;

	tree.addNode(DialogueTree::NodeType::Speaker);
	tree.addNode(DialogueTree::NodeType::Choice);

	Serializer::serialize(tree);
}

int main(int argc, char* argv[]) {
	// App setup.
	QApplication app(argc, argv);
	MainWindow* window = new MainWindow();
	window->show();
	test_node_creation();
	
	// TODO: Force visual tree to refresh for loaded test nodes.

	app.exec();

	return 0;
}