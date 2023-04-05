Target = IAO
CC = gcc

SRC = ${wildcard *.c}
OBJ = ${patsubst %.c, %.o, ${SRC}}
HEADS = ${wildcard *.h}

${Target}: ${OBJ} ${HEADS}
	ar rcs ${Target}.a ${OBJ}