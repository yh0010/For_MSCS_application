output: lab8rational.o rational8.o
	g++ lab8rational.o rational8.o -o output

lab8rational.o: lab8rational.cpp
	g++ -c lab8rational.cpp

rational8.o: rational8.cpp rational8.h
	g++ -c rational8.cpp

clean:
	rm *.o output
