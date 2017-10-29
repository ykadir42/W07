all: main.c
	gcc -o "mun" main.c
run: all
	./mun
