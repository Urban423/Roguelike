Target = Roguelike
CC = gcc

WindowsIO = ../WindowsIO/
ConsoleIO = ../ConsoleIO/
GLDir = ../GameLogic/

CFLAGS += -I${WindowsIO}
CFLAGS += -I${GLDir} 
LDFLAGS += -L${WindowsIO} -lWIO
LDFLAGS += -L${GLDir} -lGL

MAIN_C = ${wildcard *.c}
MAIN_O = ${patsubst %.c, %.o, ${MAIN_C}}

${Target}: ${MAIN_O} 
	${CC} -o ${Target} ${MAIN_O} ${LDFLAGS} -lgdi32 

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@