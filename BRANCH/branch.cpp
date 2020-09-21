#include <iostream>
#include "gitpp.h"

using namespace std;

int main(int argc, char const *argv[]) {


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
//GITPP::REPO r; for modular implementation

	/*****************************************************************/
  // Branching

		// list branches
		std::cout << "found these branches\n";

		for(GITPP::BRANCH i : r.branches()){
			std::cout << i << "\n";
		}

		cout << endl << endl;


		// creates new branch
		try{
			cout << "attempting to create a new branch..." << endl;
			r.branches().create("new_branch");
			cout << "new branch created?" << endl;
		}catch(GITPP::EXCEPTION_INVALID const&){
			std::cout << "seems to exist already\n";
		}

		cout << endl << endl;

		// list branches
		std::cout << "found these branches\n";

		for(GITPP::BRANCH i : r.branches()){
			std::cout << i << "\n";
		}

		cout << endl << endl;

		// switches branches
		// careful, only works if index is sufficiently clean
		std::cout << "switching branches\n";
		r.checkout("new_branch");
		r.checkout("master");
		std::cout << "that worked, cleaning up\n";

		r.branches().erase("new_branch");

  return 0;
}
