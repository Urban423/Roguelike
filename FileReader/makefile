Target = FileReader
CC = gcc

MathDir = ../Math/

CFLAGS += -I${MathDir}
LDFLAGS += -L${MathDir} -lmath

obj = bin
PREF_OBJ = ./${obj}/

SRC = ${wildcard *.c}
OBJ = ${patsubst %.c, ${PREF_OBJ}%.o, ${SRC}}

OBJ_DEL = ${subst /,\, ${OBJ}}

${Target}: ${OBJ}
	ar rcs lib${Target}.a $^
	
${PREF_OBJ}%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	del ${OBJ_DEL}