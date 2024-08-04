#include <iostream>

struct Conjunto{//CONJUNTO ORDENADO!!!
static constexpr int tam = 10;
char v[tam];
int n;
};

void inicializar(Conjunto &c){
    c.n = 0;
}

bool vazio(Conjunto &c){
    return (c.n == 0);
}

bool cheio(Conjunto &c){
    return (c.n == c.tam);
}

int localiza(Conjunto &c, char ch){//localiza o índice do elemento procurado
    for(int i = 0; i < c.n; i++){
        if(c.v[i] == ch) return i;
    }
   return -1;
}

bool pertence(Conjunto &c, char ch){
    int in = 0, fin = c.n-1;
    while(in <= fin){
        int m = in +(fin - in) / 2;//para evitar overflow
        if(c == c.v[m]) return true;
        if(c < c.v[m]) fin = m - 1;
        else in = m + 1;
    }
    return false;
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
         for(int j = (localiza(c, ch) + 1); j < c.n; j++){
        c.v[j - 1] = c.v[j];
        c.n--;
    }
}
//-------------------------
//Versão recursiva
bool buscaBinariaRecursiva(Conjunto &c, char ch, int inicio, int fim){
    if(inicio > fim){
        return false;
    }

    int meio = inicio + (fim - inicio) / 2;

    if(c.v[meio] == ch){
        return true;
    }
    else if(c.v[meio] < ch){
        return buscaBinariaRecursiva(c, ch, meio + 1, fim);
    }
    else{
        return buscaBinariaRecursiva(c, ch, inicio, meio - 1);
    }
}

bool pertence(Conjunto &c, char ch){
    return buscaBinariaRecursiva(c, ch, 0, c.n - 1);
}