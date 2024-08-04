#include <iostream>

struct Fila{
    static constexpr int tam = 5;
    char v[tam];
    int p, u;
};

void Inicializar(Fila &F){
    F.p = -1;
}

bool Vazia(Fila &F){
   return (F.p == -1);
}
bool Cheia(Fila &F){
    if(F.p == -1) return false;
    return (F.u + 1) % F.tam == F.p;
}

bool Inserir(Fila &F,char c){
if (Cheia(F)) return false;
if (Vazia(F)){
    F.p = F.u = 0;
}
else{
    if(F.u == F.tam - 1) F.u = 0;
    else ++F.u;//incremento vem antes   
}
F.v[F.u] = c;
return true;
}

bool Remover(Fila &F){
   if(F.p == -1) return false;
if(F.u == F.p) F.u = 0;
else F.p = (F.p + 1) % F.tam; 
return true;
}

char Consultar(Fila &F){
return F.v[F.p];
}

int main(){
    Fila F;
    Inicializar(F);
}