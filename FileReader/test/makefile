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

${Target}: clean builder test

builder: ${OBJ}
	${CC} -o ${Target} $^ ${LDFLAGS}  -lgdi32 

${bin}%.o: %.c
	${CC} ${CFLAGS} -c $^ -o $@

test:
	${Target}
	
clean:
	del ${OBJ_DEL}