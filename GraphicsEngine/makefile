Target = GE
CC = gcc

IAODir = ../Math/
CFLAGS += -I${IAODir}
LDFLAGS += -l${IAODir} -lmath

obj = bin
PREF_OBJ = ./${obj}/

SRC = ${wildcard *.c}
OBJ = ${patsubst %.c, ${PREF_OBJ}%.o, ${SRC}}
OBJ_del = ${subst /,\, ${OBJ}}

${Target}: clean build

build: ${OBJ}
	ar -rcs lib${Target}.a $^
	
${PREF_OBJ}%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@
	
clean:
	del ${OBJ_del}