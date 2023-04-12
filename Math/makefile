Target = math
CC = gcc

obj = bin
PREF_OBJ = ./${obj}/

SRC = ${wildcard *.c}
OBJ = ${patsubst %.c, ${PREF_OBJ}%.o, ${SRC}}

${Target}: ${OBJ}
	ar rcs lib${Target}.a $^
	
${PREF_OBJ}%.o: %.c
	${CC} -c $< -o $@