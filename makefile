CC = gcc
Target = Roguelike

GLdir = ./GameLogic/
IOdir = ./WindowsIO/
Maindir = ./Main/

${Target}: 
	make -C ${GLdir}
	make -C ${IOdir}
	make -C ${Maindir}
