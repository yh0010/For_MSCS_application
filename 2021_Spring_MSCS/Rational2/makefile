output: main.o rational7.o
	g++ main.o rational7.o -o output

main.o: main.cpp
	g++ -c main.cpp

rational7.o: rational7.cpp rational7.h
	g++ -c rational7.cpp

clean:
	rm *.o output
