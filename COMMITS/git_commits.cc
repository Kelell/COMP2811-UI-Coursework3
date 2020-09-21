#include <iostream>
#include "gitpp.h"

using namespace std;

int main(int argc, char const *argv[]) {

	std::string path=".";
// This can be changed for modularity later
	try{
		GITPP::REPO r(path.c_str());
		cout << "Commits for selected repository \n";

		for(auto i : r.commits()){
			cout << i.time() << " " << i.id() << " " << i.signature().name() << i.message() << "\n";
		}

	}

	catch(GITPP::EXCEPTION_CANT_FIND const&){
		GITPP::REPO r(GITPP::REPO::_create, path.c_str());
		cout<<"You have created a git repository \n";
		r.commits().create("test created from git_create.cc \n");
	} 

  return 0;
}
