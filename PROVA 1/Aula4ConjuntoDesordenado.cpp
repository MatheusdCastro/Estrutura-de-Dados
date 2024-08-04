#include <iostream>

struct Conjunto{
    static constexpr int tam = 10;
    char v[tam];
    int n;
};

void inicializar(Conjunto &c){
    c.n = 0;
}

bool pertence(Conjunto &c, char ch){
for(int i = 0; i < c.n; i++){
    if(c.v[i] == ch) return true;
}
return false;
} 

int localiza(Conjunto &c, char ch){//localiza o índice do elemento procurado
    for(int i = 0; i < c.n; i++){
        if(c.v[i] == ch) return i;
    }
   return -1;
}

void inserir(Conjunto &c, char ch){
if((!pertence(c, ch)) && (c.n < c.tam)){
    c.v[c.n] = ch;
    c.n++;
}
else std::cout << "impossivel inserir elemento"<< std::endl;
}

void remover (Conjunto &c, char ch){
    if(pertence(c, ch)){
         c.v[localiza(c, ch)] = c.v[c.n - 1];
        c.n--;
    }
}

