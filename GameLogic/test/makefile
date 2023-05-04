Target = test_GameLogic
CC = gcc

bin = ./bin/

MathDir = ../../Math
testDir = ..

CFLAGS += -I${MathDir}/
CFLAGS += -I${testDir}/



SCR = ${wildcard *.c}
OBJ = ${patsubst %.c,${bin}%.o, ${SCR}}

OBJ_DEL = ${subst /,\, ${OBJ}}

${Target}: clean builder

builder: ${OBJ}
	ar rcs -o lib${Target}.a $^

${bin}%.o: %.c
	${CC} ${CFLAGS} -c $^ -o $@

test:
	${Target}
	
clean:
	del ${OBJ_DEL}