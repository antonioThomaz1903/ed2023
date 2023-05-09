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
    
    /* teste caso 1 --> ->*/
    avl_insere(&arv,10);    
    avl_insere(&arv,15);
    avl_insere(&arv,20);
    avl_rebalancear(&arv);  
    assert(arv->item == 15);
    assert(arv->esq->item == 10);
    assert(arv->dir->item == 20);

    /* teste caso 2 --> <- */
    avl_insere(&arv,50);
    avl_insere(&arv,23);
    avl_rebalancear(&arv);  
    assert(arv->item == 15);
    assert(arv->esq->item == 10);
    assert(arv->dir->item == 23);
    assert(arv->dir->esq->item == 20);
    assert(arv->dir->dir->item == 50);

    /* teste caso 3 <-- <- */
    avl_insere(&arv,5);
    avl_insere(&arv,30);
    avl_insere(&arv,25);
    avl_rebalancear(&arv);  
    assert(arv->item == 15);
    assert(arv->esq->item == 10);
    assert(arv->esq->esq->item == 5);
    assert(arv->dir->item == 23);
    assert(arv->dir->esq->item == 20);
    assert(arv->dir->dir->item == 30);
    assert(arv->dir->dir->esq->item == 25);
    assert(arv->dir->dir->dir->item == 50);

    /* teste caso 4 <-- -> */
    avl_insere(&arv,7);
    avl_rebalancear(&arv);  
    assert(arv->item == 15);
    assert(arv->esq->item == 7);
    assert(arv->esq->esq->item == 5);
    assert(arv->esq->dir->item == 10);
    assert(arv->dir->item == 23);
    assert(arv->dir->esq->item == 20);
    assert(arv->dir->dir->item == 30);
    assert(arv->dir->dir->dir->item == 50);
    assert(arv->dir->dir->esq->item == 25);


}

int main(void){
    test_rotacao();
    test_rebalancear();
    return EXIT_SUCCESS;
}
