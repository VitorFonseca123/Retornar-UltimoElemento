#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// elemento da lista
typedef struct estr
{
    int chave;
    struct estr *prox;
} NO;
typedef struct
{
    NO *inicio;
} LISTA;

void inicializar(LISTA *l)
{
    l->inicio = NULL;
}
void exibirLista(LISTA *l)
{
    NO *p = l->inicio;
    while (p)
    {
        printf("%d ", p->chave);
        p = p->prox;
    }
}

int ultimo(LISTA *l){
    NO *p = l->inicio;
    while (p)
    {
        if(p->prox==NULL){
            return p->chave;
        }
        p=p->prox;
    }
    return -1;
    
}

int main()
{
    int vetor1[] = {1, 2, 3, 4, 5};

    LISTA l;

    inicializar(&l);
    printf("ANEXAR\n");
    int i;
    for (i = 0; i < 5; i++)
    {
        anexar(&l, vetor1[i]);
    }
    exibirLista(&l);
    printf("\n");
    printf("%d", ultimo(&l));
}
void anexar(LISTA *l, int ch)
{
    NO *novo = (NO *)malloc(sizeof(NO));
    novo->chave = ch;
    novo->prox = NULL;
    NO *p = l->inicio;
    NO *ant = NULL;

    while (p)
    {
        ant = p;
        p = p->prox;
    }
    if (ant)
        ant->prox = novo;
    else
        l->inicio = novo;
}