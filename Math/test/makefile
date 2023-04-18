Target = mathTest
CC = gcc

obj = bin
PREF_OBJ = ./${obj}/

SRC = ${wildcard *.c}
OBJ = ${patsubst %.c, ${PREF_OBJ}%.o, ${SRC}}

${Target}: ${OBJ}
	${CC} -o ${Target} $^ 
	
${PREF_OBJ}%.o: %.c
	${CC} -c $< -o $@