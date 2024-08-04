#include <iostream>

struct Fila{
    static constexpr int tam = 5;
    char v1[tam], v2[tam];
    int p, u;
};

void inicializar(Fila &f){
    f.p = -1;
}

bool isEmpty(Fila &f){
    return (f.p == -1);
}

bool isFull(Fila &f){
    if(isEmpty(f)) return false;
    return ((f.u + 1) % (2 * f.tam ) == f.p); 
}

bool inserir(Fila &f, char c){
    if(isFull(f)) return false;
    if(isEmpty(f)){
        f.u = f.p = 0;
    }
    else {
        if(f.u == (2 * f.tam) - 1) f.u = 0;
        else ++f.u;
    }
    if((f.u % f.tam) <= f.tam - 1 ) f.v1[(f.u % f.tam)] = c;
    else f.v2[(f.u % f.tam)] = c;
    return true;
}

bool remover(Fila &f){
    if(isEmpty(f)) return false;
    if(f.u == f.p) f.u = 0;
    else f.p = (f.p + 1) % f.tam;
    return true;
}

char consulta(Fila &f){
    if((f.p % f.tam <= f.tam - 1)) return f.v1[(f.p % f.tam)];
    else  return f.v2[(f.p % f.tam)];
}
int main(){
    Fila f;
    inicializar(f);
}