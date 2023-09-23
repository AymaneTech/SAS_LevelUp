all: compile

clear:
	clear
compile: main.c
	gcc main.c -o a.out
	./a.out
