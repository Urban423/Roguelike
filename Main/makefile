Target = Roguelike
CC = gcc

IAODir = ../InputAndOutputSystem/
GLDir = ../GameLogic/

CFLAGS += -I${IAODir}
CFLAGS += -I${GLDir} 
LDFLAGS += -L${IAODir} -lIAO
LDFLAGS += -L${GLDir} -lGL

MAIN_C = ${wildcard *.c}
MAIN_O = ${patsubst %.c, %.o, ${MAIN_C}}

${Target}: ${MAIN_O} 
	${CC} -o ${Target} ${MAIN_O} ${LDFLAGS}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@