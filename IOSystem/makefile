Target = IOSystem
CC = gcc

obj = bin
objDir = ./${obj}/

SRC = ${wildcard *.c}
OBJ = ${patsubst %.c, ${objDir}%.o, ${SRC}}

OBJ_DEL = ${subst /,\, ${OBJ}}

MathDir = ../Math/
WindowsIODir = ./WindowsIO/
ConsoleIODir = ./ConsoleIO/
LinuxIODir = ./LinuxIO/

CFLAGS += -I${MathDir}
CFLAGS += -I${WindowsIODir}
CFLAGS += -I${ConsoleIODir}
CFLAGS += -I${LinuxIODir}

${Target}: ${OBJ}
	make -C ${WindowsIODir}
	make -C ${ConsoleIODir}
	make -C ${LinuxIODir}
	ar rcs lib${Target}.a $^

${objDir}%.o: %.c
	${CC} ${CFLAGS}  -c $< -o $@

clean:
	del ${OBJ_DEL}