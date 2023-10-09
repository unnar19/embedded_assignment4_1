all: part1 part2a part2b part3

part1: src/main_p1.cpp
	g++ -o part1 src/main_p1.cpp

part2a: src/main_p2a.cpp
	g++ -o part2a src/main_p2a.cpp -lpthread

part2b: src/main_p2b.cpp
	g++ -o part2b src/main_p2b.cpp src/incrementTask.cpp src/decrementTask.cpp src/shared_var.cpp -Iinclude -lpthread

part3: src/main_p3.cpp
	g++ -o part3 src/main_p3.cpp src/writeToFifo.cpp src/readFromFifo.cpp src/shared_var3.cpp src/fifo.cpp -Iinclude -lpthread

