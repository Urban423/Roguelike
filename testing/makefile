Target = maintest

GameLogicDir = ../GameLogic/test/
GraphicsEngineDir = ../GraphicsEngine/test/
IOSystemDir = ../IOSystem/test/
GameLogicDir = ../GameLogic/test/
FileReaderDir = ../FileReader/test/
ErrorHadlerDir = ../ErrorHandler/test/

${Target}:
	${MAKE} -C ${GameLogicDir}
	${MAKE} -C ${GraphicsEngineDir}
	${MAKE} -C ${IOSystemDir}
	${MAKE} -C ${FileReaderDir}
	${MAKE} -C ${ErrorHadlerDir}
	
	
	${MAKE} test -C ${GameLogicDir}
	${MAKE} test -C ${GraphicsEngineDir}
	${MAKE} test -C ${IOSystemDir}
	${MAKE} test -C ${FileReaderDir}
	${MAKE} test -C ${ErrorHadlerDir}