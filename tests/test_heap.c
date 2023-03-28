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


int main(void){
    test_pai();
    return EXIT_SUCCESS;
}
