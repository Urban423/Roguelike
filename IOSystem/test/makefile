Target = test_IOSystem
CC = gcc

bin = ./bin/

WindowsDir = ../WindowsIO/
LinuxDir = ../LinuxIO/
MathDir = ../../Math
testDir = ..

CFLAGS += -I${MathDir}/
CFLAGS += -I${testDir}/
CFLAGS += -I${WindowsDir}/
CFLAGS += -I${LinuxDir}/

SCR = ${wildcard *.c}
OBJ = ${patsubst %.c,${bin}%.o, ${SCR}}

OBJ_DEL = ${subst /,\, ${OBJ}}

${Target}: clean builder

builder: ${OBJ}
	ar rcs -o lib${Target}.a $^

${bin}%.o: %.c
	${CC} ${CFLAGS} -c $^ -o $@
	
clean:
	del ${OBJ_DEL}