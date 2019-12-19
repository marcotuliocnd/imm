#include "Stack.h"
#include "cc.h"

#include "ImageMap.h"

int cc(char* sourcefile, char* destinefile){
    int label =2;
    int aux=0;
    int *m, *origem;
    int nlin,ncol,x[4]={-1,0,0,1},y[4]={0,-1,1,0};
    Stack* pilha;

    Image *image;
    image = readImageBinaryFormat(sourcefile);

    nlin = getHeight(image);
    ncol = getWidth(image);

    origem = returnArray(image);
    m = malloc(nlin*ncol*sizeof(int));

    for (int i=0; i<ncol*nlin; i++)
        m[i] = 0;

    pilha = stackCreate();
    Pixel p, p_atual;

    for(int l=0;l<ncol;l++){
        for(int k=0;k<nlin;k++){
            p.x=l;
            p.y=k;
            if (origem[p.y*ncol+p.x]==1 && m[p.y*ncol+p.x]==0)
            {
                m[p.y*ncol+p.x]=label;
                aux=stackPush(pilha, p);
                while(stackSize(pilha)!=0)
                {
                    aux=stackTop(pilha, &p_atual);
                    aux=stackPop(pilha);

                    for(int i=0;i<4;i++)
                    {
                        p.x = p_atual.x+x[i];
                        p.y = p_atual.y+y[i];
                        if (origem[p.y*ncol+p.x]==1 && m[p.y*ncol+p.x]==0)
                        {
                            m[p.y*ncol+p.x]=label;
                            aux=stackPush(pilha, p);
                        }
                    }
                }
                label++;
            }
        }
    }

    for (int i=0; i<ncol*nlin; i++)
        insertMatriz(image,m[i],i);

    convertImageIntoBinary(image, destinefile);
    return 1;
}
