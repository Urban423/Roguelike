CC = gcc
Target = Roguelike

MathDir = ./Math/
LogicDir = ./GameLogic/
GraphicsEngineDir = ./GraphicsEngine/
FileReaderDir = ./FileReader/
IODir = ./IOSystem/
MainDir = ./Main/

${Target}: clean
	${MAKE} -C ${MathDir}
	${MAKE} -C ${LogicDir}
	${MAKE} -C ${GraphicsEngineDir}
	${MAKE} -C ${FileReaderDir}
	${MAKE} -C ${IODir}
	${MAKE} -C ${MainDir}
	
clean:
	${MAKE} clean -C ${LogicDir}
	${MAKE} clean -C ${MainDir}
