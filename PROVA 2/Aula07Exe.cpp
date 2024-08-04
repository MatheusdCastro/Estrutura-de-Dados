#include <iostream>
#include <new>

int tam = 2;
struct Pilha{
    int n;//quantidade de elemento no vetor-1 e tbm o índice do último
    char *c = new char[tam];
};

bool cheia(Pilha *p){
    return (p->n == tam-1);
}

void topo(Pilha *p){
    std::cout << '\n' << p->c[p->n];
}

bool vazia(Pilha *p){
    return (p->n == -1);
}

void inicializar(Pilha *p){
    p->n = -1;
}

void empilhar(Pilha *p, char x ){
    if(cheia(p)){
        int novo_tam = 2 * tam;
        char *c2 = new char[novo_tam];
        for(int i = 0; i < tam; i++){
            c2[i] = p->c[i];
        }
        delete[] p->c;
        tam = novo_tam;
        p->c = c2;
    }
    p->c[++(p->n)] = x;
}

void desempilhar(Pilha *p){
    if(!vazia(p)){
        --(p->n);
    }
    else std::cerr << "\nERRO: A PILHA JA ESTA VAZIA!";
}

void mostrar_pilha(Pilha *p){
    for(int i = 0; i <= p->n; i++){
        std::cout << p->c[i] << " ";
    }
}

int main(){
    Pilha p;
    inicializar(&p);
    empilhar(&p,'8');
    empilhar(&p, 'E');
    empilhar(&p, 'c');
    empilhar(&p, 'R');
    empilhar(&p, '7');
    empilhar(&p,'?');
    desempilhar(&p);
    desempilhar(&p);
    empilhar(&p,'A');
    mostrar_pilha(&p);
    topo(&p);
    delete[] p.c;
}