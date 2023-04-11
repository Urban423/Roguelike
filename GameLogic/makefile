Target = GL
CC = gcc

IAODir = ../WindowsIO/
CFLAGS += -I${IAODir}
LDFLAGS += -L${IAODir} -lIAO

obj = bin
PREF_OBJ = ./${obj}/

SRC = ${wildcard *.c}
OBJ = ${patsubst %.c, ${PREF_OBJ}%.o, ${SRC}}

${Target}: ${OBJ}
	ar rcs lib${Target}.a $^
	
${PREF_OBJ}%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@