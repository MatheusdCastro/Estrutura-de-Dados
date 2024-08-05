#include <iostream>
#include <string>
#include <exception>
using namespace std;

struct Deque{
     struct Noh{
          string elem;
          Noh *esq, *dir;
     };
Noh *ESQ, *DIR;

Deque(): ESQ{nullptr}, DIR{nullptr}{}

bool vazia(){
     return (ESQ == DIR == nullptr);
}

void inserir_Esq(string s){
     if(vazia()){
          ESQ = DIR = new Noh {s, nullptr, nullptr};
     }
     else{
          // Noh *novo = new Noh {s, nullptr, ESQ};
          // ESQ->esq = novo;
          // ESQ = novo;
          ESQ->esq = new Noh {s, nullptr, ESQ};
          ESQ = ESQ->esq;
     }     
}

void inserir_Dir(string s){
     if(vazia()){
          DIR = ESQ = new Noh {s, nullptr, nullptr};
     }
     else{
          DIR->dir = new Noh {s, DIR, nullptr};
          DIR = DIR->dir;
     }
}

void remover_Esq(){

}

void remover_Dir(){

}

string consultar_Esq(){
     return ESQ->elem;
}

string consultar_Dir(){
     return DIR->elem;
}

~Deque(){

}

};