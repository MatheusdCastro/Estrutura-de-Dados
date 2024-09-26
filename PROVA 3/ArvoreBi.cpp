#include <iostream>
using namespace std;

struct ConjABB{//Arvore Binaria de Busca
    struct Noh{
        Noh *esq;//filho esq
        int elem;
        Noh *dir;//filho dir
    };
    Noh *Raiz;

    ConjABB(): Raiz{nullptr}{}

    ~ConjABB(){
        //posui algo de recursivo

    }

    void inserir(int e){
        Noh *novo = new Noh{nullptr, e, nullptr};
        if(vazio()){
            Raiz = novo; 
            return;
        }
        Noh *n = Raiz;
        while(true){
            if(e < n->elem){
                if(n->esq == null){
                    n->esq = novo;
                    return;
                }
                n = n->esq;
            }
            else{
                if(n->dir == null){
                    n->dir = novo;
                    return;
                }
                n= n->dir;
            }
        }
    }

    bool pertence(int e){
        Noh *n = Raiz;
        while(n != nullptr){
            if(e < n->elem) n = n-> esq;
            else if(e > n->elem) n = n->dir;
            else return true;
        }
        return false;
    }

    bool vazio(){
        return (Raiz == nullptr);
    }

    int altura(Noh *n){}
    if (n == nullptr) return 0;
    int alt_esq = altura(n->esq);
    int alt_dir = altura(n->dir);
    if(alt_esq < alt_dir)return alt_dir + 1;
    else return alt_esq +1;
};