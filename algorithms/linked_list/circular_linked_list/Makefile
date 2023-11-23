all: list

list: main.o list.o
	g++ -o $@ $^

main.o:main.cpp
	g++ -c $<

list.o:list.cpp
	g++ -c $<

clean:
	rm *.o list
