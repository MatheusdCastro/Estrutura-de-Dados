#include <iostream>
#include <exception>

struct Pilha{
    struct Noh{
        int elem;
        Noh *prox;
    };
    Noh *topo;
    Pilha() : topo(nullptr){}

    void empilhar(int e){
        // Noh novo = new Noh;
        // novo->elem = e;
        // novo->prox = topo;
        // topo = novo;
        topo = new Noh {e, topo};
    }

    bool vazia(){
        return (topo == nullptr);
    }

    int consultar_Topo(){
        if(!vazia()){
            return topo->elem;
        }
        else std::cerr << "Pilha vazia !" << '\n';
    }

    void desempilhar(){
        if(!vazia()){
            Noh *primeiro = topo;
            topo = topo->prox;
            delete primeiro;
        }
        else std::cerr << "Pilha vazia !" << '\n';
    }

    void imprimir(){
        Noh *contador = topo;
        while(contador != nullptr){
            std::cout << " " << contador->elem;
            contador = contador->prox;
        }
        std::cout << '\n';
    }

    ~Pilha(){
        while(!vazia()) desempilhar();
    }
};

int main(){
    try{
        Pilha p;
        p.empilhar(8);
        p.empilhar(10);
        p.empilhar(555);
        p.desempilhar();
        p.imprimir();
    }
    catch(const std::exception &e){
        std::cerr << "Falha : " << e.what() << '\n';
        return 1;
    }
}