all:	CP4

CP4:	CP4.o funcs.o UserTree.o VoteTree.o
	g++ CP4.o funcs.o UserTree.o VoteTree.o -o CP4.exe

CP4.o:	CP4.cpp
	g++ -c CP4.cpp

funcs.o: funcs.cpp
	g++ -c funcs.cpp

UserTree.o: UserTree.cpp	
	g++ -c UserTree.cpp

VoteTree.o: VoteTree.cpp	
	g++ -c VoteTree.cpp

clean:
	rm -f *.o CP4.exe
