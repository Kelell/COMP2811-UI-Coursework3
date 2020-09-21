#include <iostream>
#include <string>
using namespace std;
#include "gitpp.h"

/*It will try and check if there is a git repository (folder) in the directory.
If there isnt, it will make one and create (but not print) a commit about it.*/

/*After testing the code, delete the git repository folder to try it again from scratch.*/

void git_config()
{
	//Use exisitng code to create a repository
	std::string path=".";
	try{
		GITPP::REPO r(path.c_str());
		std::cout<<"There is already a git repository \n";
	}

	catch(GITPP::EXCEPTION_CANT_FIND const&){
		GITPP::REPO r(GITPP::REPO::_create, path.c_str());
		std::cout<<"You have created a git repository \n";
		r.commits().create("test created from git_create.cc \n");
	}
	GITPP::REPO r(path.c_str());

	//The code for the config files starts here
	//GITPP::REPO r; in the event of a moduolar function
	string input;
	std::cout << "\nGit repository configuration\n\n";
	auto c=r.config();
	//list the configurations
	GITPP::CONFIG::ITEM N=c["user.name"];
	std::cout << "Name: " << N.value() << "\n";
	GITPP::CONFIG::ITEM E=c["user.email"];
	std::cout << "Your E-mail: " << E.value() << "\n\n";
	GITPP::CONFIG::ITEM R=c["core.repositoryformatversion"];
	std::cout << "Repository Format Version: " << R.value() << "\n";
	GITPP::CONFIG::ITEM B=c["core.bare"];
	std::cout << "Bare?: " << B.value() << "\n";
	GITPP::CONFIG::ITEM F=c["core.filemode"];
	std::cout << "Filemode?: " << F.value() << "\n";
	GITPP::CONFIG::ITEM L=c["core.logallrefupdates"];
	std::cout << "Log all Ref Updates?: " << L.value() << "\n";
	//ask the user if they want to change configs
	std::cout << "\nEdit config files?\ny, yes\nn, no\n";
	std::cin >> input;
	while (input != "y") {
		if (input == "n") {
			std::cout << "\nBack to the main menu\n";
			break;
		}
		std::cout << "Please enter a valid input!\n";
		std::cin >> input;
    }
	if (input == "y"){
		//assign a new name
		std::cout << "Enter the new name\n\n";
		std::cin >> input;
		c["user.name"]= input;
		GITPP::CONFIG::ITEM N=c["user.name"];
		std::cout<< "New name is:  " << N.value() << "\n";
		//assign a new e-mail
		std::cout << "Enter the new e-mail\n\n";
		std::cin >> input;
		c["user.email"]= input;
		GITPP::CONFIG::ITEM E=c["user.email"];
		std::cout << "New name is:  " << E.value() << "\n";
	}
	return ;
}
