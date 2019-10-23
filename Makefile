
CPPOPTIONS = -c -g -Wall -std=c++0x

all: test_bst test_dict imdb

//==============================================================================
test_bst.o: test_bst.cpp bst.h bst.cpp
	g++ $(CPPOPTIONSS) -c test_bst.cpp

test_bst: test_bst.o
	g++ -o test_bst test_bst.o

test_dict.o: test_dict.cpp dict.h dict.cpp
	g++ $(CPPOPTIONSS) -c test_dict.cpp

test_dict: test_dict.o
	g++ -o test_dict test_dict.o

imdb.o: imdb.cpp dict.h dict.cpp
	g++ $(CPPOPTIONSS) -c imdb.cpp

imdb: imdb.o
	g++ -o imdb imdb.o

//==============================================================================
//==============================================================================
tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a all

