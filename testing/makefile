Target = RoguelikeTest
CC = gcc

build = build
buildDir = ./${build}/
obj = bin
objDir = ./${obj}/

testGameLogicDir = ../GameLogic/test/
testGraphicsEngineDir = ../GraphicsEngine/test/
testWindowIOIOSystemDir = ../IOSystem/WindowsIO/test/
testFileReaderDir = ../FileReader/test/
testErrorHadlerDir = ../ErrorHandler/test/
testSceneDir = ../Scene/test/

MathDir = ../Math/
IOSystem = ../IOSystem/
WindowIO = ${IOSystem}WindowsIO/
LinuxIO = ${IOSystem}LinuxIO/
ConsoleIO = ${IOSystem}ConsoleIO/
GraphicsEngineDir = ../GraphicsEngine/
SceneDir = ../Scene/
FRDir = ../FileReader/
GLDir = ../GameLogic/

CFLAGS += -I${IOSystem}
CFLAGS += -I${WindowIO}
CFLAGS += -I${LinuxIO}
CFLAGS += -I${GLDir} 
CFLAGS += -I${FRDir} 
CFLAGS += -I${MathDir} 
CFLAGS += -I${SceneDir}
CFLAGS += -I${GraphicsEngineDir}
 
CFLAGS += -I${testSceneDir}
CFLAGS += -I${testGameLogicDir}
CFLAGS += -I${testGraphicsEngineDir}
CFLAGS += -I${testWindowIOIOSystemDir}
CFLAGS += -I${testFileReaderDir} 
CFLAGS += -I${testErrorHadlerDir} 
 

LDFLAGS += -L${testSceneDir} -ltest_Scene
LDFLAGS += -L${testGameLogicDir} -ltest_GameLogic
LDFLAGS += -L${testGraphicsEngineDir} -ltest_GE
LDFLAGS += -L${testFileReaderDir} -ltest_FileReader
LDFLAGS += -L${testWindowIOIOSystemDir} -ltest_WindowsIOSystem
LDFLAGS += -L${testErrorHadlerDir} -ltest_ErrorHandler

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
	${MAKE} -C ${testGameLogicDir}
	${MAKE} -C ${testGraphicsEngineDir}
	${MAKE} -C ${testFileReaderDir}
	${MAKE} -C ${testWindowIOIOSystemDir}
	${MAKE} -C ${testErrorHadlerDir}
	${MAKE} -C ${testSceneDir}
	
	${CC} -D test -o ${Target} ${MAIN_O} ${LDFLAGS} -lgdi32 
	${Target}

${objDir}%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@
	
clean:
	del ${DEL_MAIN_O}