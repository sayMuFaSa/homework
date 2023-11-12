all: encode decode

encode:encode.o functions.o
	g++ -o $@ $^
decode:decode.o functions.o
	g++ -o $@ $^
decode.o:decode.cpp
	g++ -c $<
encode.o:encode.cpp
	g++ -c $<
functions.o:functions.cpp
	g++ -c $<

clean:
	rm decode encode *.o
