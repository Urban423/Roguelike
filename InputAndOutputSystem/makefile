Target = IAO
CC = gcc

obj = bin
PREF_OBJ = ./${obj}/

SRC = ${wildcard *.c}
OBJ = ${patsubst %.c, ${PREF_OBJ}%.o, ${SRC}}
HEADS = ${wildcard *.h}

${Target}: ${OBJ} ${HEADS}
	ar rcs lib${Target}.a $^
	
${PREF_OBJ}%.o: %.c
	${CC} -c $< -o $@