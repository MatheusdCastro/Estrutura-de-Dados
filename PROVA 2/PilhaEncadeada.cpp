#include <iostream>
#include <exception>
#include <string>
using namespace std;

struct Pilha{
    struct Noh{
        string elem;
        Noh *prox;
    };
    Noh *topo;
    
    Pilha() : topo{nullptr}{}

    void empilhar(string s){
        // Noh novo = new Noh;
        // novo->elem = e;
        // novo->prox = topo;
        // topo = novo;
        topo = new Noh {s, topo};
    }

    bool vazia(){
        return (topo == nullptr);
    }

    void consultar_Topo(){
        if(!vazia()){
            cout << "Elemento do topo eh: " << topo->elem << '\n';
        }
        else cerr << "Pilha vazia !" << '\n';
    }

    void desempilhar(){
        if(!vazia()){
            Noh *primeiro = topo;
            topo = topo->prox;
            delete primeiro;
        }
        else cerr << "Pilha vazia !" << '\n';
    }

    void imprimir(){
        Noh *contador = topo;
        while(contador != nullptr){
            cout << " " << contador->elem << '\n';
            contador = contador->prox;
        }
        cout << '\n';
    }

    ~Pilha(){
        while(!vazia()) desempilhar();
    }
};

int main(){
    try{
        Pilha p;
        p.empilhar("8");
        p.empilhar("frase aleatoria");
        p.empilhar("555");
        p.desempilhar();
        p.imprimir();
        p.consultar_Topo();
    }
    catch(const exception &e){
        cerr << "Falha : " << e.what() << '\n';
        return 1;
    }
}