a.exe: Stack.cpp main_alloc.cpp
	g++ Stack.cpp main_alloc.cpp
Stack.o: Stack.h Stack.cpp
	g++ -c -g Stack.cpp
main_alloc.o: Stack.h main_alloc.cpp
	g++ -c -g main_alloc.cpp
clean:
	del *.o a.exe