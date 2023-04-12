Target = FileReader
CC = gcc

MathDir = ../Math/
GEDir = ../GraphicsEngine/

CFLAGS += -I${MathDir}
LDFLAGS += -L${MathDir} -lmath
CFLAGS += -I${GEDir}
LDFLAGS += -L${GEDir} -lGE

obj = bin
PREF_OBJ = ./${obj}/

SRC = ${wildcard *.c}
OBJ = ${patsubst %.c, ${PREF_OBJ}%.o, ${SRC}}

${Target}: ${OBJ}
	ar rcs lib${Target}.a $^
	
${PREF_OBJ}%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@