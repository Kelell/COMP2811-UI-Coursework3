# HCI makefile
#
# GNU Make has most of the rules built in.
# https://www.gnu.org/software/make/manual/html_node/Catalogue-of-Rules.html
# no reason to copy them.

CPPFLAGS=-DTRACE_UNTESTED
CXXFLAGS=-std=c++11 -Wall -pedantic

GIT_H = gitpp.h

GIT_PROGRAMS = branch

all: ${GIT_PROGRAMS}

branch.o: CPPFLAGS+=-I.

${GIT_PROGRAMS}: LDLIBS=-lstdc++ -lgit2

${GIT_PROGRAMS:%=%.o}: ${GIT_H}

CLEANFILES = ${GIT_PROGRAMS}
clean:
	rm -f *~ *.o ${CLEANFILES}

.SUFFIXES:
.SUFFIXES: .o .cpp
