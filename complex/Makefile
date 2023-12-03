all:main

main:main.o complex.o
	g++ -o main main.o complex.o
complex.o:
	g++ -Wextra -Wall -c complex.cpp
main.o:
	g++ -Wextra -Wall -c main.cpp
clean:
	rm main *.o
