main: main.o recursion_partition.o extreme.o
	g++ -o main main.o recursion_partition.o extreme.o -std=c++11

recursion_partition: recursion_partition.o
	g++ -o recursion_partition recursion_partition.o -std=c++11

extreme: extreme.o
	g++ -o extreme extreme.o -std=c++11

main.o: main.cpp
	g++ -c main.cpp -std=c++11

recursion_partition.o: recursion_partition.cpp
	g++ -c recursion_partition.cpp -std=c++11

extreme.o: extreme.cpp
	g++ -c extreme.cpp -std=c++11
run:
	./main

clean:
	rm *.o
