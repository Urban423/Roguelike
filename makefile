CC = gcc
Target = Roguelike

MathDir = ./Math/
LogicDir = ./GameLogic/
GraphicsEngineDir = ./GraphicsEngine/
FileReaderDir = ./FileReader/
IODir = ./IOSystem/
MainDir = ./Main/
TestingDir = ./testing/

${Target}: clean
	${MAKE} -C ${MathDir}
	${MAKE} -C ${LogicDir}
	${MAKE} -C ${GraphicsEngineDir}
	${MAKE} -C ${FileReaderDir}
	${MAKE} -C ${IODir}
	
	${MAKE} -C ${TestingDir}
	
	${MAKE} -C ${MainDir}
	
clean:
	${MAKE} clean -C ${LogicDir}
	${MAKE} clean -C ${MainDir}
	${MAKE} clean -C ${FileReaderDir}
	
	${MAKE} clean -C ${GraphicsEngineDir}
	${MAKE} clean -C ${MathDir}
	${MAKE} clean -C ${IODir}
