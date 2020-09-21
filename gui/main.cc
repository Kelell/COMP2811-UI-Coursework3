#include "window.h"

#include <QApplication>
#include <iostream>
#include <unistd.h>

int argc=0;
char* argv[] = {NULL};

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	HomeWindow window;
	window.show();
	app.exec();

	// avoid segfault in QtWidget destructors.
	// _exit(0);
}
