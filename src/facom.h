#ifndef _FACOMH_
#define _FACOMH_

 /*  lista de prioridades */
int heap_pai(int filho);
int heap_filho_esq(int pai);
int heap_filho_dir(int pai);
void heap_desce(int v[], int n, int pai);
void heap_constroi(int v[],int n);
int  heap_extrai_max(int v[],int *n);
void heap_sort(int v[],int n);
void heap_altera_prioridade(int v[],int n, int pos, int novo_valor);
int e_par(int v);
 /*  arvore de busca binaria */

typedef struct _no{
    void * item;
    struct _no * esq;
    struct _no * dir;
}tno;

typedef struct _arv{
    tno * raiz;
    int (*compara)(const void *a, const void *b);
}tarv;

void abb_construir(tarv * parv, int (*compara)(const void *a, const void *b));
void abb_inserir(tarv * parv, void *pitem);
#endif 
