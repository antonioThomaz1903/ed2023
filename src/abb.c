#include<stdio.h>
#include<stdlib.h>
#include"facom.h"


void abb_construir(tarv * parv, int (*compara)(const void *a, const void *b)){
    parv->raiz = NULL;
    parv->compara = compara;
}

void abb_inserir(tarv * parv, void *pitem){
    tno ** ppno;
    tno * pno;
    ppno = &(parv->raiz);
    pno = *ppno;
    while(pno !=NULL){
                           /* 10     20 */
        if (parv->compara(pno->item,pitem)){ /* direita*/
            ppno = &(pno->dir);
            pno = *ppno;
        }else{                              /* esquerda*/
            ppno = &(pno->esq);
            pno = *ppno;
        }
    }
    if ((*ppno) == NULL){
        (*ppno) = malloc(sizeof(tno));
        (*ppno)->item = pitem;
        (*ppno)->esq = NULL;
        (*ppno)->dir = NULL;
    }
}
