#include<iostream>
using namespace std;

struct Dicionario{
    struct Noh{
        int chave;
        string valor;
        Noh *prox;
    };
    Noh *inicio;

    Dicionario() : inicio(nullptr){}
    
    void inserir(int c, string v){
        // Noh *novo = new Noh;
        // novo->chave = c;
        // novo->valor = v;
        // inicio = novo;
        inicio = new Noh{c, v, inicio};
    }
    string procurar(chave c){
        struct Busca{
            bool achou;
            string valor;
        };
        Noh *buscador = inicio;
        while(buscador != nullptr){
            if(buscador->chave == c) return buscador->valor;
            buscador = buscador->prox;
        }
        //se a chave não for encontrada
    }
    void remover(int c){
        if(procurar(c)){

        }
    }

};

