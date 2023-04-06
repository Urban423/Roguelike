Target = GL
CC = gcc

obj = bin
PREF_OBJ = ./${obj}/

SRC = ${wildcard *.c}
OBJ = ${patsubst %.c, ${PREF_OBJ}%.o, ${SRC}}

${Target}: ${OBJ}
	${CC} -o lib${Target} $^
	
${PREF_OBJ}%.o: %.c
	${CC} -c $< -o $@