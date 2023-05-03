Target = test_IOSystem
CC = gcc

bin = ./bin/

WindowsDir = ../WindowsIO/
LinuxDir = ../LinuxIO/
MathDir = ../../Math
testDir = ..

CFLAGS += -I${MathDir}/
CFLAGS += -I${testDir}/
CFLAGS += -I${WindowsDir}/
CFLAGS += -I${LinuxDir}/
LDFLAGS += -L${testDir} -lIOSystem
LDFLAGS += -L${MathDir} -lmath
LDFLAGS += -L${WindowsDir} -lWIO
LDFLAGS += -L${LinuxDir} -lLinuxIO



SCR = ${wildcard *.c}
OBJ = ${patsubst %.c,${bin}%.o, ${SCR}}

OBJ_DEL = ${subst /,\, ${OBJ}}

${Target}: clean builder

builder: ${OBJ}
	${CC} -o ${Target} $^ ${LDFLAGS}

${bin}%.o: %.c
	${CC} ${CFLAGS} -c $^ -o $@

test:
	${Target}
	
clean:
	del ${OBJ_DEL}