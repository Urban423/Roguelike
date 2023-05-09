Target = test_FileReader
CC = gcc

bin = ./bin/

MathDir = ../../Math
testDir = ..

CFLAGS += -I${MathDir}/
CFLAGS += -I${testDir}/
LDFLAGS += -L${testDir} -lFileReader
LDFLAGS += -L${MathDir} -lmath



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