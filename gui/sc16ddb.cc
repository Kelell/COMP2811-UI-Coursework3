#include "globals.h"
#include "gitpp.h"
#include <string>
#include <iostream>

#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QtWidgets>
#include <QObject>
#include <QListWidget>



namespace{

static void insert(){
	std::cout<<"nothing to search\n";
}

class GitTaskLabel : public QWidget{
public:
	GitTaskLabel() : QWidget(){


		// Layout for buttons
		QHBoxLayout* hlayout= new QHBoxLayout(this);

		/* create button */
    QLineEdit* searchBox = new QLineEdit();
		QPushButton* search = new QPushButton("search");
		QLabel* header = new QLabel("Enter text and search for results");
		hlayout->addWidget(header);
    hlayout->addWidget(searchBox);
 		hlayout->addWidget(search);







		hlayout->setAlignment(Qt::AlignLeft);
		QObject::connect(search, &QPushButton::clicked, insert);

	}
};
INSTALL_TAB(GitTaskLabel, "Search");


}
