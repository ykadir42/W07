all: main.c random_gen.c random_gen.h
	gcc -o "mun" main.c
	gcc -o "randgen" random_gen.c
run: all
	./mun
