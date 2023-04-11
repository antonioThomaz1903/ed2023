#include<stdlib.h>
#include<assert.h>
#include"../src/facom.h"

typedef struct _aluno{
    int rga;
    char nome[30];
    int idade;
}taluno;

int compara(const void *a, const void *b){
    return    (*(taluno *)a).rga - (*(taluno *)b).rga;
}

taluno * aloca_reg(int rga){
    taluno * pitem;
    pitem = malloc(sizeof(taluno));
    pitem->rga = rga;
    return pitem;
}

void test_construir(){
    tarv arv;
    abb_construir(&arv,compara);
    taluno a1;
    taluno a2;
    a1.rga = 10;
    a2.rga = 20;

    assert(arv.raiz == NULL);
    assert(arv.compara(&(a1.rga),&(a2.rga)) == -10);
    assert(arv.compara(&(a2.rga),&(a1.rga)) == 10);
    assert(arv.compara(&(a1.rga),&(a1.rga)) == 0);
    assert(arv.compara(&(a2.rga),&(a2.rga)) == 0);


}

void  test_inserir(){
    tarv arv;
    taluno * a1;
    tno * pnode;
    abb_construir(&arv,compara);

    abb_inserir(&arv,aloca_reg(10));
    
    pnode = arv.raiz;
    a1 = aloca_reg(10);
    assert(arv.compara(pnode->item,a1) == 0);
    assert(pnode->esq == NULL);
    assert(pnode->dir == NULL);
 
     
    abb_inserir(&arv,aloca_reg(20));
    assert(pnode->esq == NULL);
    a1->rga = 10;assert(arv.compara(pnode->item,a1) == 0);
    a1->rga = 20;assert(arv.compara(pnode->dir->item,a1) == 0);
    assert(pnode->dir->dir == NULL);
    assert(pnode->dir->esq == NULL);


}
void  test_destruir(){
}

int main(void){
    test_construir();
    test_inserir();
    test_destruir();
    return EXIT_SUCCESS;
}
