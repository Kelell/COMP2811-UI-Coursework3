#include "globals.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QtWidgets>
#include <QObject>

namespace{

class GitTaskLabel : public QWidget{
public:
	GitTaskLabel() : QWidget(){
		QVBoxLayout* layout= new QVBoxLayout;
		/* create button */
		QPushButton* createRepoButton = new QPushButton("Create Repo");


		layout->addWidget(new QLabel("Click here to create a git repository"));
		setLayout(layout);

		layout->setAlignment(Qt::AlignCenter);
		layout->addWidget(createRepoButton);
	}
};
INSTALL_TAB(GitTaskLabel, "Create/Select git repository");

}
