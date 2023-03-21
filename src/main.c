#include<stdio.h>
#include<stdlib.h>
#include"facom.h"

int main(void){
    int i;
    for(i=0;i<10;i++){
        if (e_par(i)) printf("%d par\n",i);
        else printf("%d  impar\n",i);
    }
    return EXIT_SUCCESS;
}
