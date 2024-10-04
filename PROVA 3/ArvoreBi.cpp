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
        //posui algo de recursivo pois percorre a árvore e deleta cada nó
        destruirABB(Raiz);
    }
    void destruirABB(Noh *n){
        if(n == nullptr) return;
        destruirABB(n->esq);
        destruirABB(n->dir);
        delete n;
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

    void remover(int e){
        Noh *n = Raiz;
        Noh *pai = nullptr;
        while(n != nullptr){
            if(e < n->elem){
                pai = n;
                n = n->esq;
            }
            else if(e > n->elem){
                pai = n;
                n = n->dir;
            }
            else break;
        }
        if(n == nullptr) return;//e não pertence
        //para 0 e 1 filho
        if(n->dir == nullptr){
            if(n == Raiz) Raiz = n->esq:
            else if(n == pai->esq) pai->esq = n->esq;
            else pai->dir = n->esq;
        }
        else if(n->esq == nullptr){
            if(n == Raiz) Raiz = n->dir;
            else if(n == pai->esq) pai->esq = n->dir;
            else pai->dir = n->dir;
        }
        else{
            Noh *paiMenor = n;//pai do menor na subárvore direita
            Noh *menor = n->dir;//menor da subárvore direita
            while(menor->esq != nullptr){
                paiMenor = menor;
                menor = menor->esq;
            }
            n->elem = menor->elem;
            
            if(paiMenor->esq == menor) paiMenor->esq = menor->dir;
            else paiMenor->dir = menor->dir;
            delete menor;
        }
        if(n != nullptr) delete n;
    }

    Noh* removerRec(Noh *raiz, int e){
        if(raiz == nullptr) return raiz;
        else if(e < raiz->elem) raiz->esq = removerRec(raiz->esq, e);
        else if(e > raiz->elem) raiz->dir = removerRec(raiz->dir, e);
        else{
            //caso 1: 0 filho
            if(raiz->esq == nullptr && raiz->dir == nullptr){
                delete raiz;
                raiz = nullptr;
                // return raiz;
            }
            //caso 2: 1 filho
            else if(raiz->esq == nullptr){
                Noh *temp = raiz;
                raiz = raiz->dir;
                delete temp;
                // return raiz;
            }
            else if(raiz->dir == nullptr){
                Noh *temp = raiz;
                raiz = raiz->esq;
                delete temp;
                // return raiz;
            }
            // caso 3; 2 filhos
            else{
                Noh* temp = raiz->dir;
                while(temp->esq != nullptr){
                    temp = temp->esq;
                }//achei o mínimo da esquerda
                raiz->elem = temp->elem;
                raiz->dir = removerRec(raiz->dir, temp->elem);

            }
        }
        return raiz;
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

    int altura(Noh *n){
    if (n == nullptr) return 0;
    int alt_esq = altura(n->esq);
    int alt_dir = altura(n->dir);
    if(alt_esq < alt_dir)return alt_dir + 1;
    else return alt_esq +1;
    }  

    int acharMax(){
        if(Raiz != nullptr){
            Noh *atual = Raiz;
            while(atual->dir != nullptr) atual = atual->dir;
            return atual->elem;
        }
        else return;
    }

    int acharMin(){
        Noh *atual = Raiz;
        if(Raiz != nullptr){
            while(atual->esq != nullptr){
                atual = atual->esq;
            }
            return atual->elem;
        }
    }

    int acharMinRec(Noh *raiz){
        if(raiz->esq == nullptr) return raiz->elem;
        return acharMinRec(raiz->esq);
    }

};