output: code.o time.o
	g++ code.o time.o -o output

code.o: code.cpp
	g++ -c code.cpp

time.o: time.cpp time.h
	g++ -c time.cpp

clean:
	rm *.o output
