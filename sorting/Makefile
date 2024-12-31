
default: sorting-c-array sorting-std-vector

sorting-std-vector: build/sorting-std-vector inputs/1
	build/sorting-std-vector < inputs/1
	build/sorting-std-vector < inputs/2
	build/sorting-std-vector < inputs/3
	build/sorting-std-vector < inputs/4

sorting-c-array: build/sorting-c-array
	build/sorting-c-array < inputs/1


# ############################
# BUILDS
# ############################

build/sorting-c-array: sorting-c-array.c
	gcc sorting-c-array.c -o build/sorting-c-array

build/sorting-std-vector: sorting-std-vector.cpp
	g++ sorting-std-vector.cpp -o build/sorting-std-vector