CC = g++
CXXFLAGS = -std=c++17
OBJS = insertion_sort.o merge_sort.o quick_sort.o counting_sort.o mapped_counting_sort.o radix_sort.o utils.o main.o
SRCS = $(OBJS:.o=.c)

insertion_sort.o : insertion_sort.h insertion_sort.cc utils.o
	$(CC) $(CXXFLAGS) -c insertion_sort.cc

merge_sort.o : merge_sort.h merge_sort.cc utils.o
	$(CC) $(CXXFLAGS) -c merge_sort.cc

quick_sort.o : quick_sort.h quick_sort.cc utils.o
	$(CC) $(CXXFLAGS) -c quick_sort.cc

counting_sort.o : counting_sort.h counting_sort.cc
	$(CC) $(CXXFLAGS) -c counting_sort.cc

mapped_counting_sort.o : mapped_counting_sort.h mapped_counting_sort.cc
	$(CC) $(CXXFLAGS) -c mapped_counting_sort.cc

radix_sort.o : radix_sort.h radix_sort.cc
	$(CC) $(CXXFLAGS) -c radix_sort.cc

utils.o : utils.h utils.cc
	$(CC) $(CXXFLAGS) -c utils.cc

main.o : main.cc utils.h insertion_sort.h merge_sort.h quick_sort.h counting_sort.h mapped_counting_sort.h radix_sort.h
	$(CC) $(CXXFLAGS) -c main.cc

main : $(OBJS)
	$(CC) $(OBJS) -o sort

clean : 
	rm -f $(OBJS) sort