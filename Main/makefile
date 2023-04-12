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

CFLAGS += -I${IOSystem}
CFLAGS += -I${WindowIO}
CFLAGS += -I${LinuxIO}
CFLAGS += -I${GLDir} 
CFLAGS += -I${FRDir} 
CFLAGS += -I${MathDir} 
CFLAGS += -I${GraphicsEngineDir}
 
LDFLAGS += -L${IOSystem} -lLinuxIO
LDFLAGS += -L${LinuxIO} -lIOSystem
LDFLAGS += -L${WindowIO} -lWIO
LDFLAGS += -L${GLDir} -lGL
LDFLAGS += -L${FRDir} -lFileReader
LDFLAGS += -L${GraphicsEngineDir} -lGE
LDFLAGS += -L${MathDir} -lmath

MAIN_C = ${wildcard *.c}
MAIN_O = ${patsubst %.c, ${objDir}%.o, ${MAIN_C}}

${Target}: ${MAIN_O} 
	${CC} -o ${buildDir}${Target} ${MAIN_O} ${LDFLAGS} -lgdi32 

${objDir}%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@