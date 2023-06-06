
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define SEED    0x12345678

typedef struct {
     uintptr_t * table;
     int size;
     int max;
     uintptr_t deleted;
     char * (*get_key)(void *);
}thash;


uint32_t hashf(const char* str, uint32_t h){
    /* One-byte-at-a-time Murmur hash 
    Source: https://github.com/aappleby/smhasher/blob/master/src/Hashes.cpp */
    for (; *str; ++str) {
        h ^= *str;
        h *= 0x5bd1e995;
        h ^= h >> 15;
    }
    return h;
}


int hash_insere(thash * h, void * bucket){
}



int hash_constroi(thash * h,int nbuckets, char * (*get_key)(void *) ){
}


void * hash_busca(thash h, const char * key){
}

int hash_remove(thash * h, const char * key){
}

void hash_apaga(thash *h){
    int pos;
    for(pos =0;pos< h->max;pos++){
        if (h->table[pos] != 0){
            if (h->table[pos]!=h->deleted){
                free((void *)h->table[pos]);
            }
        }
    }
    free(h->table);
}



void test_hash(){
    thash h;
    int nbuckets = 10;
    hash_constroi(&h,nbuckets,get_key);
    assert(hash_insere(&h,aloca_aluno("edson","0123456789"))==EXIT_SUCCESS);
    assert(hash_insere(&h,aloca_aluno("edson","0123456789"))==EXIT_SUCCESS);
    assert(hash_insere(&h,aloca_aluno("edson","0123456789"))==EXIT_SUCCESS);
    assert(hash_insere(&h,aloca_aluno("edson","0123456789"))==EXIT_SUCCESS);
    assert(hash_insere(&h,aloca_aluno("edson","0123456789"))==EXIT_SUCCESS);
    assert(hash_insere(&h,aloca_aluno("edson","0123456789"))==EXIT_SUCCESS);
    assert(hash_insere(&h,aloca_aluno("edson","0123456789"))==EXIT_SUCCESS);
    assert(hash_insere(&h,aloca_aluno("edson","0123456789"))==EXIT_SUCCESS);
    assert(hash_insere(&h,aloca_aluno("edson","0123456789"))==EXIT_SUCCESS);
    assert(hash_insere(&h,aloca_aluno("edson","0123456789"))==EXIT_SUCCESS);
    assert(hash_insere(&h,aloca_aluno("edson","0123456789"))==EXIT_FAILURE);
    hash_apaga(&h);
}
void test_search(){
    thash h;
    int nbuckets = 10;
    taluno * aluno;
    hash_constroi(&h,nbuckets,get_key);
    assert(hash_insere(&h,aloca_aluno("edson","0123456789"))==EXIT_SUCCESS);
    assert(hash_insere(&h,aloca_aluno("takashi","1123456789"))==EXIT_SUCCESS);
    assert(hash_insere(&h,aloca_aluno("matsubara","2123456789"))==EXIT_SUCCESS);

    aluno = hash_busca(h,"edson");
    assert(aluno->cpf[0]=='0');
    aluno = hash_busca(h,"takashi");
    assert(aluno->cpf[0]=='1');
    aluno = hash_busca(h,"matsubara");
    assert(aluno->cpf[0]=='2');
    aluno = hash_busca(h,"patricia");
    assert(aluno == NULL);

    hash_apaga(&h);
}


void test_remove(){
    thash h;
    int nbuckets = 10;
    taluno * aluno;
    hash_constroi(&h,nbuckets,get_key);
    assert(hash_insere(&h,aloca_aluno("edson","0123456789"))==EXIT_SUCCESS);
    assert(hash_insere(&h,aloca_aluno("takashi","1123456789"))==EXIT_SUCCESS);
    assert(hash_insere(&h,aloca_aluno("matsubara","2123456789"))==EXIT_SUCCESS);

    aluno = hash_busca(h,"edson");
    assert(aluno->cpf[0]=='0');
    aluno = hash_busca(h,"takashi");
    assert(aluno->cpf[0]=='1');
    aluno = hash_busca(h,"matsubara");
    assert(aluno->cpf[0]=='2');
    aluno = hash_busca(h,"patricia");
    assert(aluno == NULL);

    assert(h.size == 3);
    assert(hash_remove(&h,"edson")==EXIT_SUCCESS);
    aluno = hash_busca(h,"edson");
    assert(aluno == NULL);
    assert(h.size == 2);

    assert(hash_remove(&h,"edson")==EXIT_FAILURE);

    aluno = hash_busca(h,"matsubara");
    assert(aluno->cpf[0]=='2');


    hash_apaga(&h);

}



int main(int argc, char* argv[]){
    test_hash();
    test_search();
    test_remove();
    return 0;
}

