#include <iostream>
#include <string>
using namespace std;

struct DicioTH{//TABELA HASH
    struct Noh{
        int chave;
        string elem;
        Noh *prox;
    };
    int m, n;
    Noh sent;
    Noh **T;// é um vetor de ponteiros para listas encadeadas

    int h(int c){//função de dispersão
        return c % m;
    }
    
    DicioTH(): m{1}, n{0}{
        T = new Noh* [m];
        T[0] = &sent;
    }

    ~DicioTH(){
        // só delete[] T ? R= não, tem q desalocar cada nó, pois desalocaria somente o vetor para ponteiros, mas os ponteiros em si ainda existem
    }

    void redimensionar(int novo_tam){
        Noh **U = new Noh*[novo_tam];
        int tam_atual = m;
        m = novo_tam;
        for(int i = 0; i < novo_tam; i++) U[i] = &sent;
        for(int i = 0; i < tam_atual; i++){
            Noh *n = T[i];
            while(n != sent){
                Noh *p = n->prox;
                int j = h(n->chave);
                n->prox = U[j];
                U[j] = n;
                n = p;
            }
        }
        delete[] T;
        T = U;
    }

    void inserir(int c, string v){
        if(m == n) redimensionar(2*m);
        int i = h(c);
        T[i] = new Noh{c, v, T[i]};
        ++n;
    }

};