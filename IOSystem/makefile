Target = IOSystem
CC = gcc

obj = bin
objDir = ./${obj}/

SRC = ${wildcard *.c}
OBJ = ${patsubst %.c, ${objDir}%.o, ${SRC}}

${Target}: ${OBJ}
	ar rcs lib${Target}.a $^

${objDir}%.o: %.c
	${CC} -c $< -o $@