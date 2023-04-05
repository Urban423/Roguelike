Target = Roguelike
CC = gcc
SRC = $


all: main.exe

main.exe: main.o
	 ${CC} -o ${Target} main.o

main.o: main.c
	 gcc -c main.c
     
clean:
	 rm main.o main.exe