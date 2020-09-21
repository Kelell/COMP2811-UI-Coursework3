#include "globals.h"
#include "gitpp.h"
// #include "bs15av.h"
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


// checks for repo; creates repo if non already exists
GITPP::REPO repoCheck(){
	std::cout << "\nbs15av repoCheck(): ";

	std::string path=".";
	try{
		GITPP::REPO r(path.c_str());
		std::cout<<"a git repository exists\n";
	}

	catch(GITPP::EXCEPTION_CANT_FIND const&){
		GITPP::REPO r(GITPP::REPO::_create, path.c_str());
		std::cout<<"You have created a git repository \n";
		r.commits().create("test created from git_create.cc \n"); // test commit

	}
	GITPP::REPO r(path.c_str());

	// creates test branch
	try{
		std::cout << "bs15av: attempting to create test_branch\n";
		r.branches().create("test_branch");
		std::cout << "bs15av: test_branch created\n";
	}catch(GITPP::EXCEPTION_INVALID const&){
		std::cout << "bs15av: test_branch seems to exist already\n";
	}

	return r;

} // repoCheck()


}





namespace{

class GitTaskLabelBranch : public QWidget{
public:
	GitTaskLabelBranch() : QWidget(){




		/*************/

		// Layout for buttons
		QHBoxLayout* hlayout= new QHBoxLayout(this);

		/* create button */
		QPushButton* cobutt = new QPushButton("Checkout");


		// List of Branches
		QListWidget* lw = new QListWidget(this);

		// check for repository
		GITPP::REPO r = std::repoCheck();


		// branch("test_branch",r);


		// add branches to lw
		for(GITPP::BRANCH i : r.branches()){

			// conv branch name into QString
			std::string str = i.name();
			const char* cstr =  str.c_str();
			QString br_name = cstr;

			lw->addItem(br_name);
		}

		// checkout and list horizontal layout
		hlayout->addWidget(lw);
		hlayout->addWidget(cobutt);

		// set outer horizontal layout
		setLayout(hlayout);

		hlayout->setAlignment(Qt::AlignLeft);


		/* Checkout */
		// checkout("test_branch", r); // seg fault?

		/* branch clean up */

	}

	// Checkout to branch _br; input = BRANCH
	void checkout(GITPP::BRANCH _br, GITPP::REPO r){

		std::string str = _br.name();
		const char* cstr =  str.c_str();

		std::cout << "bs15av checkout(): checking out to: " << cstr << "\n";

		// checkout to _br
		r.checkout(cstr);

		std::cout << "bs15av checkout(): checkout successful\n";


} // checkout()

// Checkout to branch _br; input = cstring branch name
void checkout(std::string _br, GITPP::REPO r){


	std::cout << "bs15av checkout(): checking out to: " << _br << "\n";

	// checkout to _br
	r.checkout(_br);

	std::cout << "bs15av checkout(): checkout successful\n";
	// std::cout << "bs15av checkout(): cleaning up\n"; // DELETE BRANCHES?

} // checkout()



	// Branch out to _brname :: not implemented yet...
	void branch(std::string _brname, GITPP::REPO r){

		std::cout << "bs15av branch(): " << _brname << "\n";

		// creates new branch
		try{
			std::cout << "bs15av branch(): attempting to create" << _brname << "\n";
			r.branches().create(_brname);
			std::cout << "bs15av branch(): "<< _brname  << "created?\n";
		}catch(GITPP::EXCEPTION_INVALID const&){
			std::cout << "seems to exist already\n";
		}


	} // branch()
};
INSTALL_TAB(GitTaskLabelBranch, "Branch");

}
