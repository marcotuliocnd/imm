typedef struct Matriz Matriz;

Matriz* createMatriz(int rows, int columns);
void freeMatriz(Matriz *matriz);
int insertMatriz(Matriz *matriz, int num);
int printMatriz(Matriz *matriz);
int getColumns(Matriz *matriz);
int getRows(Matriz *matriz);
int *getLine(Matriz *matriz, int line);
int replaceMatriz(Matriz *matriz, int base);
int getEachElementInOrder(Matriz *matriz);
