#pragma once

#include <QMainWindow>

class QLabel;
class QWidget;

class HomeWindow: public QMainWindow {
public:
	HomeWindow();

private:
	void createWindowContent();
	void createMenuAndStatusBar();

private: // widgets we own
	QLabel* _label;
	QWidget* _mainWidget;
};
