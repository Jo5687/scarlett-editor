#pragma once

#include <QMainWindow>
#include <dialoguetree.h>
#include <memory>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr) {};

private:
	std::unique_ptr<DialogueTree> m_dialogueTree;
};