#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct _aluno{
    int rga;
    char nome[30];
    char sobrenome[30];
    int idade;
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
    taluno * a1;
    taluno * a2;
    a1 = (taluno *) a;
    a2 = (taluno *) b;
    return a1->rga - a2->rga;
    //return (*((taluno *)a)).rga - (*((taluno *)b)).rga;
}
int compara_idade(const void *a, const void *b){
    taluno * a1;
    taluno * a2;
    a1 = (taluno *) a;
    a2 = (taluno *) b;
    return a1->idade - a2->idade;
    //return (*((taluno *)a)).rga - (*((taluno *)b)).rga;
}

void avlg_constroi(tarv * parv, int (*compara)(const void *a, const void *b)){
    parv->raiz = NULL;
    parv->compara = compara; 
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
void test_compara_idade(){
    tarv arv;
    taluno a1;
    taluno a2;
    avlg_constroi(&arv,compara_rga);
    a1.idade = 10;
    a2.idade = 20;
    assert(arv.compara(&a1,&a2)==-10);
}


int main(void){
    test_compara();
    test_compara_idade();
    return EXIT_SUCCESS;
}
