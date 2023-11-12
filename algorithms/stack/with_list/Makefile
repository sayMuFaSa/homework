all:stack

stack:main.o list.o
	g++ -o $@ $^

list.o:list.cpp
	g++ -c $<

main.o:main.cpp
	g++ -c $<

clean:
	rm *.o stack
