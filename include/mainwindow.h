#pragma once

#include <QMainWindow>
#include <dialoguetree.h>
#include <interface/menubar.h>
#include <memory>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr) {};

private:
	std::unique_ptr<DialogueTree> m_dialogueTree = std::make_unique<DialogueTree>();
	std::unique_ptr<MenuBar> m_menuBar = std::make_unique<MenuBar>();
};