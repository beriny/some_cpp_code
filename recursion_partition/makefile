main: main.o recursion_partition.o extreme.o ksmallvalue.o
	g++ -o main main.o recursion_partition.o extreme.o ksmallvalue.o -std=c++11

main.o: main.cpp
	g++ -c main.cpp -std=c++11

recursion_partition.o: recursion_partition.cpp
	g++ -c recursion_partition.cpp -std=c++11

extreme.o: extreme.cpp
	g++ -c extreme.cpp -std=c++11

ksmallvalue.o: ksmallvalue.cpp
	g++ -c ksmallvalue.cpp -std=c++11

run:
	./main

clean:
	rm *.o
