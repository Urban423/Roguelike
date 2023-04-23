Target = test_GE
CC = gcc

Include = ../
Include += -I../../Math/
CFLAGS += -I${Include}

SCR = ${wildcard *.c}
OBJ = ${patsubst %.c,%.o, ${SCR}}

${Target}: clean builder

builder: ${OBJ}
	${CC} ${CFLAGS} -o ${Target} $^ -Lmath.a -LGE.a

%.o: %.c
	${CC} ${CFLAGS} -c  $< -o $@

test:
	${Target}
	
clean:
	del ${OBJ}