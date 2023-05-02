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

int main(void){
    test_rotacao();
    return EXIT_SUCCESS;
}
