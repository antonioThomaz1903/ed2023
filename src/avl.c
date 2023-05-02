#include<stdio.h>
#include<stdlib.h>
#include "avl.h"

int max(int a,int b){
    return a>b?a:b;
}

int altura(tnode *arv){
    int ret;
    if (arv==NULL){
        ret = 0;
    }else{
        ret = arv->h;
    }
    return ret;
}


void avl_insere(tnode ** parv,titem item){
    if (*parv == NULL){
        *parv = (tnode *) malloc(sizeof(tnode));
        (*parv)->item = item;
        (*parv)->esq = NULL;
        (*parv)->dir = NULL;
        (*parv)->h = 1;

    }else if(((*parv)->item - item)>0){
        avl_insere(&(*parv)->esq,item);
    }else{
        avl_insere(&(*parv)->dir,item);
    }
    (*parv)->h = max(altura((*parv)->esq),altura((*parv)->dir)) + 1;
    /* rebalancear(parv);*/
}
