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

class GitTaskLabel : public QWidget{
public:
	GitTaskLabel() : QWidget(){


		// Layout for buttons
		QHBoxLayout* hlayout= new QHBoxLayout(this);

		/* create button */
    QTextEdit* searchBox = new QTextEdit();
		QPushButton* search = new QPushButton("search");

    hlayout->addWidget(searchBox);
    hlayout->addWidget(search);






		hlayout->setAlignment(Qt::AlignLeft);
	}
};
INSTALL_TAB(GitTaskLabel, "Search");

}
