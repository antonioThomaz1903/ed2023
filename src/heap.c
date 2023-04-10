#include<stdio.h>
#include<stdlib.h>
#include"facom.h"

int heap_pai(int filho){
    return (int)(filho-0.5)/2.0;
}

int heap_filho_esq(int pai){
    return pai*2 + 1;
}
int heap_filho_dir(int pai){
    return pai*2 + 2;
}

void troca(int *v1, int *v2){
    int aux = *v1;
    *v1 = *v2;
    *v2 = aux;
}
void heap_desce(int v[], int n, int pai){
    int e,d,maior;

    e = heap_filho_esq(pai);
    d = heap_filho_dir(pai);

    maior = pai;
    if ( e< n && v[e] > v[pai]){
        maior = e;
    }
    if ( d < n && v[d] > v[maior]){
        maior = d;
    }
    if (maior != pai){
        troca(&v[pai],&v[maior]);
        heap_desce(v,n,maior);
    }

}


void heap_constroi(int v[],int n){
    int i;
    int ultimo = n-1;
    for (i = heap_pai(ultimo);i>=0;i--){
        heap_desce(v,n,i);
    }
}


int  heap_extrai_max(int v[],int *n){
    int max = v[0];
    int ultimo = *n -1;
    troca(&v[0],&v[ultimo]);
    heap_desce(v,ultimo,0);
    *n = *n-1;
    return max;
}
