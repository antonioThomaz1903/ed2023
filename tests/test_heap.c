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



int main(void){
    test_pai();
    return EXIT_SUCCESS;
}
