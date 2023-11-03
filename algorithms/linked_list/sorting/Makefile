all:list

list:main.o list.o sort.o
	g++ -o $@ $^

sort.o:sort.cpp
	g++ -c $<

list.o:list.cpp
	g++ -c $<

main.o:main.cpp
	g++ -c $<

clean:
	rm *.o list
