a.exe: main3-copy.o
	g++ main3-copy.o
main3.o: FiniteQueue-copy.h main3-copy.cpp
	g++ -c -g main3-copy.cpp
clean:
	del *.o a.exe