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
#include <QLineEdit>


namespace{

	 static void newUser()
	 {
		std::cout<<"test\n";
	 }

	 static void newEmail()
 	 {
 		std::cout<<"test2\n";
 	 }

	static void insertUser()
	 {
		std::string path=".";
		GITPP::REPO r(path.c_str());
		auto c=r.config();
		std::string str = "test";
		c["user.name"]= str;
	 }

	 static void insertEmail()
	 {
		std::string path=".";
		GITPP::REPO r(path.c_str());
		auto c=r.config();
		std::string str = "test";
		c["user.email"]= str;
	 }

class GitTaskLabel : public QWidget{
public:
	GitTaskLabel() : QWidget(){
		setFixedSize(600, 400); //hosted here to remove the need for a homepage
		//Vertical box for the configs
		QGridLayout* info=new QGridLayout;
		std::string path=".";
		GITPP::REPO r(path.c_str());
		auto c=r.config();
		//List config values
		info->addWidget(new QLabel("Current Configurations"),0,1);
		GITPP::CONFIG::ITEM N=c["user.name"];
		std::string str = N.value();
		const char* cstr =  str.c_str();
		QString user = cstr;new QLineEdit("change email");
		info->addWidget(new QLabel("Name: "+user),1,0);
		GITPP::CONFIG::ITEM E=c["user.email"];
		str = E.value();
		cstr =  str.c_str();
		QString email = cstr;
		info->addWidget(new QLabel("Your E-mail: "+email),2,0);
		GITPP::CONFIG::ITEM R=c["core.repositoryformatversion"];
		str = R.value();
		cstr =  str.c_str();
		QString form = cstr;
		info->addWidget(new QLabel("Repository Format Version: "+form),3,0);
		GITPP::CONFIG::ITEM B=c["core.bare"];
		str = B.value();
		cstr =  str.c_str();
		QString bare = cstr;
		info->addWidget(new QLabel("Empty repository: "+bare),4,0);
		GITPP::CONFIG::ITEM F=c["core.filemode"];
		str = F.value();
		cstr =  str.c_str();
		QString file = cstr;
		info->addWidget(new QLabel("Filemode: "+file),5,0);
		info->setAlignment(Qt::AlignLeft);
		GITPP::CONFIG::ITEM L=c["core.logallrefupdates"];
		str = L.value();
		cstr =  str.c_str();
		QString update = cstr;
		info->addWidget(new QLabel("Form: "+update),6,0);
		//The editing section
		QLineEdit* userText = new QLineEdit;
		userText->setPlaceholderText("Change Username");
		QObject::connect(userText,&QLineEdit::textChanged,newUser);
		info->addWidget(userText,1,1);
		QLineEdit* emailText = new QLineEdit;
		QObject::connect(emailText,&QLineEdit::textChanged,newEmail);
		emailText->setPlaceholderText("Change Email");
		info->addWidget(emailText,2,1);
		QPushButton* changeUser = new QPushButton("Enter");
		QObject::connect(changeUser,&QPushButton::clicked,insertUser);
		info->addWidget(changeUser,1,3);
		QPushButton* changeEmail = new QPushButton("Enter");
		QObject::connect(changeEmail,&QPushButton::clicked,insertEmail);
		info->addWidget(changeEmail,2,3);
		info->setColumnStretch(1, 10);
		setLayout(info);
	}
};

INSTALL_TAB(GitTaskLabel, "Configure git repo");

}
