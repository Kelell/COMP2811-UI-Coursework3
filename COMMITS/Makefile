CPPFLAGS=-DTRACE_UNTESTED
CXXFLAGS=-std=c++11 -Wall -pedantic

GIT_HCI_PROGRAMS = commits
GIT_H = gitpp.h

GIT_PROGRAMS = commits

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

