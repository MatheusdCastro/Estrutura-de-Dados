#include<iostream>

using namespace std;

struct Fila
{
    static constexpr int tam_v=5;
    char v[tam_v];
    int p,u;
};

void inicializar(Fila &F){
    F.p=-1;
}
bool vazia(Fila &F){
    return F.p==-1;
}