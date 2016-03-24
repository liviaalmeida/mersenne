all: mersenne

mersenne: mersenne.c
	gcc -o mersenne mersenne.c -lm
