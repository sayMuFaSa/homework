all:main

main:main.o complex.o
	g++ -o main main.o complex.o
complex.o:
	g++ -c complex.cpp
main.o:
	g++ -c main.cpp
clean:
	rm main *.o
