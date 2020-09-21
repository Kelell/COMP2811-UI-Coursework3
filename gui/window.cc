#include "window.h"
#include "tabs.h"
#include "globals.h"

//#include <QtWidgets> // qt5 only?
#include <QHBoxLayout>
#include <QStatusBar>
#include <QMenuBar>
#include <QApplication>


HomeWindow::HomeWindow()
{
	createWindowContent();
	createMenuAndStatusBar();
	setFixedSize(700, 500);
}


void HomeWindow::createWindowContent()
{
	// Create layout

	TabDialog* tabs=new TabDialog();

	QHBoxLayout* layout=new QHBoxLayout();
	layout->addStretch();

	// transfer ownership?
	layout->addWidget(tabs);
	layout->addStretch();

	// Put layout in the middle of the window

	_mainWidget = new QWidget();
	_mainWidget->setLayout(layout);

	setCentralWidget(_mainWidget);
}


void HomeWindow::createMenuAndStatusBar(){

	//statusBar()->showMessage("");

	QMenu* fileMenu = menuBar()->addMenu("&File");
	
	QAction* quit = fileMenu->addAction("Quit");
	quit->setShortcuts(QKeySequence::Quit);
	quit->setStatusTip("Quit the application");

	QMenu* editMenu = menuBar()->addMenu("&Edit");
	QAction* editConf = editMenu->addAction("Edit Config file");
	editConf->setStatusTip("Edit the repository's config file.");

	QMenu* gitMenu = menuBar()->addMenu("&Git");
	
	QAction* gitSel = gitMenu->addAction("&Select/Create Repository");
	gitSel->setStatusTip("Select an existing repository, or initialise a new one.");

	QAction* branchSel = gitMenu->addAction("&Branch Manager");
	branchSel->setStatusTip("Manage your branches.");

	QAction* comView = gitMenu->addAction("&List Commits.");
	gitSel->setStatusTip("List commits for selected repository.");

	QAction* keySearch = gitMenu->addAction("&Keyword Search");
	keySearch->setStatusTip("Search commits for keywords.");

	connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
}
