
CLANG=-Wall
CLANG+=-Werror

default: sorting-c-array

sorting-c-array: build/sorting-c-array
	build/sorting-c-array < inputs/1
	build/sorting-c-array < inputs/2

clear: clean

clean:
	rm -rf build/*

# ############################
# BUILDS
# ############################

build/sorting-c-array: sorting-c-array.c
	gcc $(CLANG) sorting-c-array.c -o build/sorting-c-array
