typedef struct Matriz Matriz;

Matriz* createMatriz(int rows, int columns);
void freeMatriz(Matriz *matriz);
int insertMatriz(Matriz *matriz, int num, int pos);
int printMatriz(Matriz *matriz);
int getColumns(Matriz *matriz);
int getRows(Matriz *matriz);
int *getLine(Matriz *matriz, int line);
int replaceMatriz(Matriz *matriz, int base);
int getEachElementInOrder(Matriz *matriz);
int getElementInPoint(Matriz *matriz, int pos);
int *returnArray(Matriz *matriz);
int printOne(Matriz *matriz, int pos);
