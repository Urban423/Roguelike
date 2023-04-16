CC = gcc
Target = Roguelike

MathDir = ./Math/
LogicDir = ./GameLogic/
GraphicsEngineDir = ./GraphicsEngine/
FileReaderDir = ./FileReader/
IODir = ./IOSystem/
MainDir = ./Main/

${Target}: 
	make -C ${MathDir}
	make -C ${LogicDir}
	make -C ${GraphicsEngineDir}
	make -C ${FileReaderDir}
	make -C ${IODir}
	make -C ${MainDir}
	
clean:
	${MAKE} clean -C ${LogicDir}
	${MAKE} clean -C ${MainDir}
