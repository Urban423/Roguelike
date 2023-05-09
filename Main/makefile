Target = Roguelike
CC = gcc

build = build
buildDir = ./${build}/
obj = bin
objDir = ./${obj}/

MathDir = ../Math/
IOSystem = ../IOSystem/
WindowIO = ${IOSystem}WindowsIO/
LinuxIO = ${IOSystem}LinuxIO/
ConsoleIO = ${IOSystem}ConsoleIO/
GraphicsEngineDir = ../GraphicsEngine/
FRDir = ../FileReader/
GLDir = ../GameLogic/
SceneDir = ../Scene/

CFLAGS += -I${IOSystem}
CFLAGS += -I${WindowIO}
CFLAGS += -I${LinuxIO}
CFLAGS += -I${GLDir} 
CFLAGS += -I${FRDir} 
CFLAGS += -I${MathDir} 
CFLAGS += -I${GraphicsEngineDir}
CFLAGS += -I${SceneDir}
 
LDFLAGS += -L${SceneDir} -lScene
LDFLAGS += -L${IOSystem} -lLinuxIO
LDFLAGS += -L${LinuxIO} -lIOSystem
LDFLAGS += -L${WindowIO} -lWIO
LDFLAGS += -L${GLDir} -lGL
LDFLAGS += -L${FRDir} -lFileReader
LDFLAGS += -L${GraphicsEngineDir} -lGE
LDFLAGS += -L${MathDir} -lmath

MAIN_C = ${wildcard *.c}
MAIN_O = ${patsubst %.c, ${objDir}%.o, ${MAIN_C}}
DEL_MAIN_O = ${subst /,\, ${MAIN_O}}

${Target}: ${MAIN_O} 
	${CC} -o ${buildDir}${Target} ${MAIN_O} ${LDFLAGS} -lgdi32 

${objDir}%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@
	
clean:
	del ${DEL_MAIN_O}