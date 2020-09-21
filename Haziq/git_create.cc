#include <iostream>
#include "gitpp5.h"

/*It will try and check if there is a git repository (folder) in the directory.
If there isnt, it will make one and create (but not print) a commit about it.*/

/*After testing the code, delete the git repository folder to try it again from scratch.*/

int main()
{
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
}
