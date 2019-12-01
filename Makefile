LIBS     = ./src/libs
MAINPATH = ./src
BIN      = ./bin
DIST     = ./dist

all: libbed app

app:
	gcc -std=c11 $(MAINPATH)/main.c $(BIN)/*.o -o $(DIST)/imm

Matriz.o: $(LIBS)/Matriz/Matriz.c
	gcc -c $(LIBS)/Matriz/Matriz.c -o $(BIN)/Matriz.o

ImageMap.o: $(LIBS)/ImageMap/ImageMap.c
	gcc -c $(LIBS)/ImageMap/ImageMap.c $(BIN)/Matriz.o -o $(BIN)/ImageMap.o

Miscelaneous.o: $(LIBS)/misc/Miscelaneous.c
	gcc -c $(LIBS)/misc/Miscelaneous.c -o $(BIN)/Miscelaneous.o

libbed: Matriz.o ImageMap.o Miscelaneous.o

run:
	$(DIST)/imm

clean:
	rm $(BIN)/*.o
	rm $(DIST)/*
