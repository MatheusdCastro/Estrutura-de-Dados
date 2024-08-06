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
          return (ESQ == nullptr && DIR == nullptr);//return(ESQ==DIR==nullptr)não funciona, pois é uma comparação, não uma atribuição
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
          if(!vazia()){
               Noh *aux = ESQ;
               ESQ = ESQ->dir;
               if(ESQ == nullptr){
                    DIR = nullptr;
               }
               else{
                    ESQ->esq = nullptr;
               }
               delete aux;
          }
          else{
               cerr <<"Deque vazio !"<< '\n';
          }
     }

     void remover_Dir(){
          if(!vazia()){
               Noh *aux = DIR;
               DIR = DIR->esq;
               if(DIR == nullptr){
                    ESQ = nullptr;
               }
               else{
                    DIR->dir = nullptr;
               }
               delete aux;
          }
          else{
               cerr <<"Deque vazio !"<< '\n';
          }
     }

     string consultar_Esq(){
          if(!vazia()) return ESQ->elem;
     }

     string consultar_Dir(){
          if(!vazia()) return DIR->elem;
     }

     void imprimir(){
          Noh *contador = ESQ;
          cout << "<";
          while(contador != nullptr){
               cout << " " << contador->elem;
               contador = contador->dir;
          }
          cout << " >" << '\n';
     }

     ~Deque(){
          while(!vazia()) remover_Dir();//poderia usar também o remover_Esq()
     }
};

int main(){
    try{
        Deque d;
        d.inserir_Esq("frase");
        d.inserir_Esq("88");
        d.inserir_Dir("sim");
        d.remover_Esq();
        d.remover_Dir();
        d.inserir_Dir("300mil");
        d.inserir_Dir("WHAT");
        d.inserir_Esq("ElementoF");      
        d.imprimir();
    }
    catch(const exception &e){
        cerr << "Falha : " << e.what() << '\n';
        return 1;
    }
}