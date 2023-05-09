Target = Scene
CC = gcc

obj = bin
objDir = ./${obj}/

SRC = ${wildcard *.c}
OBJ = ${patsubst %.c, ${objDir}%.o, ${SRC}}

OBJ_DEL = ${subst /,\, ${OBJ}}

MathDir = ../Math/
IOSystem = ../IOSystem/
WindowIO = ${IOSystem}WindowsIO/
LinuxIO = ${IOSystem}LinuxIO/
ConsoleIO = ${IOSystem}ConsoleIO/
GraphicsEngineDir = ../GraphicsEngine/
FRDir = ../FileReader/
GLDir = ../GameLogic/

CFLAGS += -I${IOSystem}
CFLAGS += -I${WindowIO}
CFLAGS += -I${LinuxIO}
CFLAGS += -I${GLDir} 
CFLAGS += -I${FRDir} 
CFLAGS += -I${MathDir} 
CFLAGS += -I${GraphicsEngineDir}

${Target}: ${OBJ}
	ar rcs lib${Target}.a $^

${objDir}%.o: %.c
	${CC} ${CFLAGS}  -c $< -o $@

clean:
	del ${OBJ_DEL}