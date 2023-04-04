#include<stdio.h>
#include<stdlib.h>
#include"../src/facom.h"
#include<assert.h>


void test_pai(){
    assert(heap_pai(0)==0);
    assert(heap_pai(1)==0);
    assert(heap_pai(2)==0);
    assert(heap_pai(3)==1);
    assert(heap_pai(4)==1);
    assert(heap_pai(5)==2);
    assert(heap_pai(6)==2);
    assert(heap_pai(7)==3);
    assert(heap_pai(8)==3);
}

void test_filhos(){
    assert(heap_filho_esq(0)==1);
    assert(heap_filho_esq(1)==3);
    assert(heap_filho_esq(2)==5);


    assert(heap_filho_dir(0)==2);
    assert(heap_filho_dir(1)==4);
    assert(heap_filho_dir(2)==6);

}

void test_desce(){
    /* inicialização*/
    int n = 10;
    int v[10] = {26,7,14,16,8,9,11,4,12,6};

    /* execução */
    int i = 1;
    heap_desce(v,n,i);
    
    /* teste*/
    assert(v[1] == 16);
    assert(v[3] == 12);
    assert(v[8] == 7);
    
     
    heap_desce(v,n,4);
    assert(v[4] == 8);
    assert(v[9] == 6);

    heap_desce(v,n,6);
    assert(v[6] == 11);
}


void test_constroi_heap(){
    int v[10] = {8,5,4,2,1,3,6,7,9,10};

    heap_constroi(v,10);
    assert(v[0] == 10);
    assert(v[1] == 9);
    assert(v[2] == 6);
    assert(v[3] == 8);
    assert(v[4] == 5);
    assert(v[5] == 3);
    assert(v[6] == 4);
    assert(v[7] == 7);
    assert(v[8] == 2);
    assert(v[9] == 1);
}

void test_extrai_max(){

    int v[10] = {8,5,4,2,1,3,6,7,9,10};
    int n = 10;
    heap_constroi(v,n);
    int max = heap_extrai_max(v,&n);
    assert(max == 10);
    assert(v[0] == 9);
    assert(v[1] == 8);
    assert(v[3] == 7);
    assert(v[7] == 1);
}
int main(void){
    test_pai();
    test_filhos();
    test_desce();
    test_constroi_heap();
    test_extrai_max();
    return EXIT_SUCCESS;
}
