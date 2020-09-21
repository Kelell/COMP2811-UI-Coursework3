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


namespace std {


class GITCOMMIT : public QWidget{

public:
	GITCOMMIT() : QWidget(){

	// Initial Layout
	QHBoxLayout* hlayout= new QHBoxLayout();
	
	// grab from global

	GITPP::REPO r;

	// Textbox config
	
	QTextEdit* textbox = new QTextEdit();
	textbox->setReadOnly(true);

	for(auto i:r.commits()){
		std::string commits = i.time() + "\n" + "\t" + i.id() + " - " + i.signature().name() + "\n\t" + i.message()+ "\n";
		QString q_commit = QString::fromStdString(commits);
		textbox->append(q_commit);
	}

	// Present layout
	hlayout->addWidget(textbox);
	setLayout(hlayout);
	hlayout->setAlignment(Qt::AlignLeft);
}

	
};
INSTALL_TAB(GITCOMMIT, "COMMIT");

}

