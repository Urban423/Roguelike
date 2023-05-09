Target = Roguelike
CC = gcc

build = build
buildDir = ./${build}/
obj = bin
objDir = ./${obj}/

MathDir = ../Math/

CFLAGS += -I${MathDir} 
 
LDFLAGS += -L${MathDir} -lmath

MAIN_C = ${wildcard *.c}
MAIN_O = ${patsubst %.c, ${objDir}%.o, ${MAIN_C}}
DEL_MAIN_O = ${subst /,\, ${MAIN_O}}

${Target}: ${MAIN_O} 
	${CC} -o ${Target} ${MAIN_O} ${LDFLAGS} -lgdi32 
	${Target}

${objDir}%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@
	
clean:
	del ${DEL_MAIN_O}