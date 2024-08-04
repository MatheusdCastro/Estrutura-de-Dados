#include <iostream>

struct Conjunto{//CONJUNTO ORDENADO!!!
static constexpr int tam = 10;
char v[tam];
int n;
};

void inicializar(Conjunto &c){
    c.n = 0;
}

bool pertence(Conjunto &c, char ch){
    int in = 0, fin = c.n-1;
    while(in <= fin){
        int m = in +(fin- in) / 2;//para evitar overflow
        if(c == c.v[m]) return true;
        if(c < c.v[m]) fin = m - 1;
        else in = m + 1;
    }
    return false;
}