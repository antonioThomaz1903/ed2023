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
