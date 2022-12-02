CC = g++
CXXFLAGS = -std=c++17

apsp.o : apsp.cc
	$(CC) $(CXXFLAGS) -c apsp.cc

apsp : apsp.o
	$(CC) apsp.o -o apsp

clean : 
	rm -f apsp.o apsp