Target = test_Scene
CC = gcc

bin = ./bin/

IOSystem = ../../IOSystem/
GraphicsEngineDir = ../../GraphicsEngine/
FRDir = ../../FileReader/
WindowIO = ${IOSystem}WindowsIO/
LinuxIO = ${IOSystem}LinuxIO/
GLDir = ../../GameLogic/

MathDir = ../../Math
testDir = ..

CFLAGS += -I${IOSystem}/
CFLAGS += -I${GraphicsEngineDir}/
CFLAGS += -I${WindowIO}/
CFLAGS += -I${LinuxIO}/
CFLAGS += -I${FRDir}/
CFLAGS += -I${GLDir}/
CFLAGS += -I${MathDir}/
CFLAGS += -I${testDir}/

SCR = ${wildcard *.c}
OBJ = ${patsubst %.c,${bin}%.o, ${SCR}}

OBJ_DEL = ${subst /,\, ${OBJ}}

${Target}: clean builder

builder: ${OBJ}
	ar rcs -o lib${Target}.a $^

${bin}%.o: %.c
	${CC} ${CFLAGS} -c $^ -o $@
	
clean:
	del ${OBJ_DEL}