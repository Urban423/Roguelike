Target = test_GE
CC = gcc

Include = ../
Include += -I../../Math/
CFLAGS += -I${Include}

SCR = ${wildcard *.c}
OBJ = ${patsubst %.c,%.o, ${SCR}}

${Target}: clean builder

builder: ${OBJ}
	${CC} -o ${Target} $^

%.o: %.c
	${CC} ${CFLAGS} -c  $< -o $@ -lmath.a -lGE.a

test:
	${Target}
	
clean:
	del ${OBJ}