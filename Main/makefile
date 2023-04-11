Target = Roguelike
CC = gcc

build = build
buildDir = ./${build}/
obj = bin
objDir = ./${obj}/

WindowsIO = ../WindowsIO/
ConsoleIO = ../ConsoleIO/
GLDir = ../GameLogic/

CFLAGS += -I${WindowsIO}
CFLAGS += -I${GLDir} 
LDFLAGS += -L${WindowsIO} -lWIO
LDFLAGS += -L${GLDir} -lGL

MAIN_C = ${wildcard *.c}
MAIN_O = ${patsubst %.c, ${objDir}%.o, ${MAIN_C}}

${Target}: ${MAIN_O} 
	${CC} -o ${buildDir}${Target} ${MAIN_O} ${LDFLAGS} -lgdi32 

${objDir}%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@