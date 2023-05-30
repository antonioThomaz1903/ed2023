#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct _aluno{
    int rga;
    char nome[30];
    char sobrenome[30];
}taluno;

typedef struct _node{
    void * item;
    struct _node *esq;
    struct _node *dir;
    int h;
}tnode;

typedef struct _arv{
    tnode * raiz;
    int (*compara)(const void *a, const void *b);
}tarv;

int compara_rga(const void *a, const void *b){
    return 1;
}

void avlg_constroi(tarv * parv, int (*compara)(const void *a, const void *b)){
}



void test_compara(){
    tarv arv;
    taluno a1;
    taluno a2;
    avlg_constroi(&arv,compara_rga);
    a1.rga = 10;
    a2.rga = 20;
    assert(arv.compara(&a1,&a2)==-10);
}

int main(void){
    test_compara();
    return EXIT_SUCCESS;
}
