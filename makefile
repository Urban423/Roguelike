CC = gcc
Target = Roguelike

MathDir = ./Math/
SceneDir = ./Scene/
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
	${MAKE} -C ${SceneDir}
	
	
	
	${MAKE} -C ${MainDir}
	
clean:
	${MAKE} clean -C ${LogicDir}
	${MAKE} clean -C ${MainDir}
	${MAKE} clean -C ${FileReaderDir}
	${MAKE} clean -C ${SceneDir}
	
	${MAKE} clean -C ${GraphicsEngineDir}
	${MAKE} clean -C ${MathDir}
	${MAKE} clean -C ${IODir}
