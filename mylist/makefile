all: make clean

make: run.o
	g++ -o run parse.cpp mylist.cpp -lstdc++

run.o: parse.cpp mylist.cpp mylist.h
	g++ -c parse.cpp mylist.cpp -lstdc++

clean:
	rm *.o

