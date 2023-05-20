Target = GL
CC = gcc

MathDir = ../Math/
FileDir = ../FileReader/
CFLAGS += -I${MathDir}
CFLAGS += -I${FileDir}

obj = bin
PREF_OBJ = ./${obj}/

SRC = ${wildcard *.c}
OBJ = ${patsubst %.c, ${PREF_OBJ}%.o, ${SRC}}
DEL_OBJ = ${subst /,\,${OBJ}}

${Target}: ${OBJ}
	ar rcs lib${Target}.a $^
	
${PREF_OBJ}%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@
	
clean:
	del ${DEL_OBJ}