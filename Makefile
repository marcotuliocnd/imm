LIBS     = ./src/libs
MAINPATH = ./src
BIN      = ./bin
DIST     = ./dist
PAGES    = ./src/pages

all: libbed app

app:
	gcc -std=c11 $(MAINPATH)/main.c $(BIN)/*.o -o $(DIST)/imm

Matriz.o: $(LIBS)/Matriz/Matriz.c
	gcc -c $(LIBS)/Matriz/Matriz.c -o $(BIN)/Matriz.o

ImageMap.o: $(LIBS)/ImageMap/ImageMap.c
	gcc -c $(LIBS)/ImageMap/ImageMap.c $(BIN)/Matriz.o -o $(BIN)/ImageMap.o

Stack.o: $(LIBS)/Stack/Stack.c
	gcc -c $(LIBS)/Stack/Stack.c $(BIN)/Matriz.o $(BIN)/ImageMap.o -o $(BIN)/Stack.o

DinamicStack.o: $(LIBS)/DinamicStack/DinamicStack.c
	gcc -c $(LIBS)/DinamicStack/DinamicStack.c $(BIN)/Matriz.o $(BIN)/ImageMap.o -o $(BIN)/DinamicStack.o

Miscelaneous.o: $(LIBS)/misc/Miscelaneous.c
	gcc -c $(LIBS)/misc/Miscelaneous.c -o $(BIN)/Miscelaneous.o

routes.o: $(MAINPATH)/routes.c
	gcc -c $(MAINPATH)/routes.c -o $(BIN)/routes.o

OpenImage.o: $(PAGES)/OpenImage/OpenImage.c
	gcc -c $(PAGES)/OpenImage/OpenImage.c -o $(BIN)/OpenImage.o

ConvertImage.o: $(PAGES)/ConvertImage/ConvertImage.c
	gcc -c $(PAGES)/ConvertImage/ConvertImage.c -o $(BIN)/ConvertImage.o

SegmentImage.o: $(PAGES)/SegmentImage/SegmentImage.c
	gcc -c $(PAGES)/SegmentImage/SegmentImage.c -o $(BIN)/SegmentImage.o

ComponenteConexo.o: $(PAGES)/ComponenteConexo/ComponenteConexo.c
	gcc -c $(PAGES)/ComponenteConexo/ComponenteConexo.c -o $(BIN)/ComponenteConexo.o

LabImage.o: $(PAGES)/LabImage/LabImage.c
	gcc -c $(PAGES)/LabImage/LabImage.c -o $(BIN)/LabImage.o

libbed: Matriz.o ImageMap.o Stack.o DinamicStack.o Miscelaneous.o OpenImage.o ConvertImage.o SegmentImage.o ComponenteConexo.o LabImage.o routes.o

run:
	$(DIST)/imm

clean:
	rm $(BIN)/*.o
	rm $(DIST)/*
