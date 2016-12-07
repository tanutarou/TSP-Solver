all: tsp make_input
tsp: tsp.cpp
	g++ -std=c++11 tsp.cpp -o tsp
make_input: make_input.cpp
	g++ -std=c++11 make_input.cpp -o make_input

