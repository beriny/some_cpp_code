main: main.o recursion_partition.o extreme.o
	g++ -std=c++0x  -o main main.o recursion_partition.o extreme.o

main.o: main.cpp
	g++ -std=c++0x -c main.cpp 

recursion_partition.o: recursion_partition.cpp
	g++ -std=c++0x -c recursion_partition.cpp

extreme.o: extreme.cpp
	g++ -std=c++0x -c extreme.cpp

run:
	./main

clean:
	rm *.o
