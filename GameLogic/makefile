Target = GL
CC = gcc

MathDir = ../Math/
CFLAGS += -I${MathDir}
LDFLAGS += -L${MathDir} -lmath
IODir = ../WindowsIO/
CFLAGS += -I${IODir}
LDFLAGS += -L${IODir} -lWIO

obj = bin
PREF_OBJ = ./${obj}/

SRC = ${wildcard *.c}
OBJ = ${patsubst %.c, ${PREF_OBJ}%.o, ${SRC}}

${Target}: ${OBJ}
	ar rcs lib${Target}.a $^
	
${PREF_OBJ}%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@