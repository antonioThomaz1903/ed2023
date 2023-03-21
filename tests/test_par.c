#include<stdlib.h>
#include<assert.h>
#include"../src/facom.h"

void test_par()
{

    assert(e_par(1)==0);

    assert(e_par(2)==1);

    assert(e_par(10)==1);

}



int main(void){
    test_par();
    return EXIT_SUCCESS;
}
