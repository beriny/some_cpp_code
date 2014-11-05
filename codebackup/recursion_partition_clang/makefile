main: main.o recursion_partition.o extreme.o ksmallvalue.o
	gcc -o main main.o recursion_partition.o extreme.o ksmallvalue.o -std=c11

main.o: main.c
	gcc -c main.c -std=c11

recursion_partition.o: recursion_partition.c
	gcc -c recursion_partition.c -std=c11

extreme.o: extreme.c
	gcc -c extreme.c -std=c11

ksmallvalue.o: ksmallvalue.c
	gcc -c ksmallvalue.c -std=c11

run:
	./main

clean:
	rm *.o
