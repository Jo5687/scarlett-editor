#pragma once

#include <QMenuBar>

class MenuBar : QMenuBar
{
public:
	MenuBar(QWidget* parent = nullptr) {};
	~MenuBar() {};

private:
	void loadMenuBar();
};