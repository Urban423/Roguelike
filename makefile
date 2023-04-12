CC = gcc
Target = Roguelike

MathDir = ./Math/
LogicDir = ./GameLogic/
GraphicsEngineDir = ./GraphicsEngine/
FileReaderDir = ./FileReader/
IOdir = ./WindowsIO/
Maindir = ./Main/

${Target}: 
	make -C ${MathDir}
	make -C ${LogicDir}
	make -C ${GraphicsEngineDir}
	make -C ${FileReaderDir}
	make -C ${IOdir}
	make -C ${Maindir}
