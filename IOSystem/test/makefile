
bin = ./bin/

SCR = ${wildcard *.c}
OBJ = ${patsubst %.c,${bin}%.o, ${SCR}}

IncludeFlags = -I../Windows/
IncludeFlags += -I../

CFlags = -L../ -lIOSystem.a

testIOSystem: ${OBJ}
	gcc -o testIOSystem $^ ${CFlags}

${bin}%.o: %.c
	gcc ${IncludeFlags} -c $< -o $@