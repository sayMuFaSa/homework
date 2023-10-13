all:main
main:main.o class.o
	g++ -g -o $@ $^

main.o:main.cpp
	g++ -Wall -g -c $<
class.o:class.cpp
	g++ -Wall -g -c $<

run:all
	./main
clean:
	rm *.o main
