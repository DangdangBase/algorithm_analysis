#!/bin/bash

echo '-----------insertion sort-----------'
./sort insertion 1
./sort insertion 2
./sort insertion 3
./sort insertion 4
./sort insertion 5

echo '-----------merge sort-----------'
./sort merge 1
./sort merge 2
./sort merge 3
./sort merge 4
./sort merge 5

echo '-----------quick sort-----------'
./sort quick 1
./sort quick 2
./sort quick 3
./sort quick 4
./sort quick 5

echo '-----------counting sort-----------'
./sort counting 1
./sort counting 2

echo '-----------mapped counting sort-----------'
./sort mapped_counting 1
./sort mapped_counting 2
./sort mapped_counting 3
./sort mapped_counting 4
./sort mapped_counting 5

echo '-----------radix sort-----------'
./sort radix 1
./sort radix 2
./sort radix 3
./sort radix 4
./sort radix 5