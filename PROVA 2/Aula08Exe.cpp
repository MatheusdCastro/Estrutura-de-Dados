#include <iostream>
#include <new>

struct Fila{
    int tam = 2;
    char *c = new char[tam];
    int p,u;
};

void inicializar(Fila *f){
    f->p = -1;
}

bool cheia(Fila *f){
    if(f->p == -1) return false;
    return ((f->u + 1) % f->tam == f->p);
}

bool vazia(Fila *f){
    return (f->p == -1);
}

void enfilar(Fila *f, char x){
    if(vazia(f)) f->p = f->u; 
    if(cheia(f)){
        int novo_tam = 2 * f->tam;
        char *c2 = new char[novo_tam];
        for(int i = 0; i < f->tam; i++){//Pensar em uma lógica melhor, organizando o p e u
            c2[i] = f->c[i];
        }
        delete[] f->c;
        f->tam = novo_tam;
        f->c = c2;
    }
    else{
        if(f->u == f->tam -1) f->u = -1; // será se o problema está nesse tipo de condição? pq agr n tem problema se ficar "cheia"
    }
    f->c[++(f->u)] = x;
}

void desenfilar(Fila *f){
    if(!vazia(f)){
        if(f->u == f->p) f->u = -1;
        f->p = (f->p + 1) % f->tam;
    }
    else std::cerr << "\nA FILA JA ESTA VAZIA!";
}

void consultar(Fila *f){
    if(!vazia(f)) std::cout << "\nO primeiro fa fila eh: " << f->c[f->p];
    else std::cerr << "\nERRO: A FILA JA ESTA VAZIA!";
}

int main(){
    Fila f;
    inicializar(&f);
    delete[] f.c;
}