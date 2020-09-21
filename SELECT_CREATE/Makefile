# HCI makefile
#
# GNU Make has most of the rules built in.
# https://www.gnu.org/software/make/manual/html_node/Catalogue-of-Rules.html
# no reason to copy them.

CPPFLAGS=-DTRACE_UNTESTED
CXXFLAGS=-std=c++11 -Wall -pedantic

GIT_HCI_PROGRAMS = git_create
GIT_H = gitpp5.h

GIT_PROGRAMS = git_create

all: ${GIT_PROGRAMS}

hello_git.o: CPPFLAGS+=-I.

${GIT_PROGRAMS}: LDLIBS=-lstdc++ -lgit2

${GIT_PROGRAMS:%=%.o}: ${GIT_H}

CLEANFILES = ${GIT_PROGRAMS}
clean:
	rm -f *~ *.o ${CLEANFILES}

#hci.o: hci.h

.SUFFIXES:
.SUFFIXES: .o .cc
