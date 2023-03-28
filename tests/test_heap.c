#include<stdio.h>
#include<stdlib.h>
#include"../src/facom.h"
#include<assert.h>


void test_pai(){
    assert(heap_pai(0)==0);
    assert(heap_pai(1)==0);
}


int main(void){
    test_pai();
    return EXIT_SUCCESS;
}
