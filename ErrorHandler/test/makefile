Target = test_ErrorHandler
CC = gcc

bin = ./bin/

MathDir = ../../Math
testDir = ..

CFLAGS += -I${MathDir}/
CFLAGS += -I${testDir}/
LDFLAGS += -L${testDir} -lErrorHandler
LDFLAGS += -L${MathDir} -lmath



SCR = ${wildcard *.c}
OBJ = ${patsubst %.c,${bin}%.o, ${SCR}}

OBJ_DEL = ${subst /,\, ${OBJ}}

${Target}: clean builder
	${Target}.exe

builder: ${OBJ}
	${CC} -o ${Target} $^ ${LDFLAGS}

${bin}%.o: %.c
	${CC} ${CFLAGS} -c $^ -o $@

test:
	${Target}
	
clean:
	del ${OBJ_DEL}