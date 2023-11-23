all:horizontal upward downward

upward:vertical_upward.cpp
	g++ -Wall -o $@ $<

downward:vertical_downward.cpp
	g++ -Wall -o $@ $<

horizontal:horizontal.cpp
	g++ -Wall -o $@ $<

clean:
	rm horizontal upward downward
