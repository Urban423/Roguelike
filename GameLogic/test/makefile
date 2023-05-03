Target = test_GameLogic
CC = gcc

bin = ./bin/

MathDir = ../../Math
testDir = ..

CFLAGS += -I${MathDir}/
CFLAGS += -I${testDir}/
LDFLAGS += -L${testDir} -lGL
LDFLAGS += -L${MathDir} -lmath



SCR = ${wildcard *.c}
OBJ = ${patsubst %.c,${bin}%.o, ${SCR}}

OBJ_DEL = ${subst /,\, ${OBJ}}

${Target}: clean builder

builder: ${OBJ}
	${CC} -o ${Target} $^ ${LDFLAGS}

${bin}%.o: %.c
	${CC} ${CFLAGS} -c $^ -o $@

test:
	${Target}
	
clean:
	del ${OBJ_DEL}