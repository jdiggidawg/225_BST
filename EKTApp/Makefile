all: EKTApp

EKTApp: main.o EKTApp.o KlingonDictionary.o Word.o
	g++ -Wall main.o EKTApp.o KlingonDictionary.o Word.o -o EKTApp

main.o: main.cpp EKTApp.hpp
	g++ -Wall -c main.cpp 

EKTApp.o: EKTApp.cpp EKTApp.hpp KlingonDictionary.hpp
	g++ -Wall -c EKTApp.cpp

KlingonDictionary.o: KlingonDictionary.cpp KlingonDictionary.hpp Word.hpp BST.hpp
	g++ -Wall -c KlingonDictionary.cpp

Word.o: Word.cpp Word.hpp
	g++ -Wall -c Word.cpp



clean:
	rm -f EKTApp *.o