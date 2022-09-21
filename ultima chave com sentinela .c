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
    NO *sent;
    NO *inicio;
} LISTA;

void inicializar(LISTA *l)
{
    l->sent = (NO *)malloc(sizeof(NO));
    l->inicio = l->sent;
}
void exibirLista(LISTA *l)
{
    NO *p = l->inicio;
    while (p != l->sent)
    {
        printf("%d ", p->chave);
        p = p->prox;
    }
}

NO *ultimo(LISTA l)
{
    NO *p = l.inicio;
    if (p == l.sent)
        return (NULL);
    while (p->prox != l.sent)
        p = p->prox;
    return (p);
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
    NO *UltimoElem = ultimo(l);
    printf("ultimo :%d", UltimoElem->chave);
}
void anexar(LISTA *l, int ch)
{
    NO *novo;
    NO *ant;
    ant = ultimo(*l);
    novo = (NO *)malloc(sizeof(NO));
    novo->chave = ch;
    novo->prox = l->sent;
    if (ant == NULL)
        l->inicio = novo;
    else
        ant->prox = novo;
}