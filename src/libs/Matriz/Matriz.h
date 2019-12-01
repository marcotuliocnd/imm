typedef struct Matriz Matriz;

Matriz* createMatriz(int rows, int columns);
void freeMatriz(Matriz *matriz);
int insertMatriz(Matriz *matriz, int num);
int printMatriz(Matriz *matriz);
