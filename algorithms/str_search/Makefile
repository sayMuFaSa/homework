all:search

search:main.o
	g++ $^ -o $@
main.o:main.cpp
	g++ -Wall -c $<
clean:
	rm *.o search
