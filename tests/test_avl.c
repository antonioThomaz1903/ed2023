#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include "../src/avl.h"

void test_rotacao(){
    tnode * arv;
    arv = NULL;
    assert(arv == NULL);
    avl_insere(&arv,35);
    avl_insere(&arv,20);
    avl_insere(&arv,40);
    avl_insere(&arv,10);
    avl_insere(&arv,30);
}

void test_rebalancear(){
    tnode * arv;
    arv = NULL;
    assert(arv == NULL);
    avl_insere(&arv,10);
    avl_insere(&arv,15);
    avl_insere(&arv,20);
    avl_rebalancear(&arv);
    assert(arv->item == 15);
    assert(arv->esq->item == 10);
    assert(arv->dir->item == 20);


}

int main(void){
    test_rotacao();
    test_rebalancear();
    return EXIT_SUCCESS;
}
