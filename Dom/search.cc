#include <iostream>
#include "gitpp5.h"

/*below code checks for repo if not creates repo if not one already */

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
