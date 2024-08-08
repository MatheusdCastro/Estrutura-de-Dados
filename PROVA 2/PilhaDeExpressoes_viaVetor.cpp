#include <iostream>
#include <string>
#include <cctype>
#include <exception>

using namespace std;

struct Pilha{
    int n;//quantidade de elemento no vetor-1 e tbm o índice do último
    string *c = new string[tam];
    int tam;

    Pilha(): n{-1}, tam{2}{}

    bool cheia(){
        return (n == tam-1);
    }

    void topo(){
        std::cout << '\n' << c[n];
    }

    bool vazia(){
        return (n == -1);
    }

    void empilhar(string x){
        if(cheia()){
            int novo_tam = 2 * tam;
            string *c2 = new string[novo_tam];
            for(int i = 0; i < tam; i++){
                c2[i] = c[i];
            }
            delete[] c;
            tam = novo_tam;
            c = c2;
        }
        c[++(n)] = x;
    }

    void desempilhar(){
        if(!vazia()){
            --(n);
        }
        else std::cerr << "\nERRO: A PILHA JA ESTA VAZIA!";
    }

    void mostrar_pilha(){
        for(int i = 0; i <= n; i++){
            std::cout << c[i] << " ";
        }
    }

    ~Pilha(){
        delete[] c;
    }

    void ler_Entrada(){//pré condição: entrada já formatada e sem caracteres inválidos
        string entrada, numero;
        cout<<"Digite a expressao: "<<'\n';
        getline(cin, entrada);
        for(char caractere : entrada){
            if(caractere == ' ') continue;
            if(isdigit(caractere)){
                numero += caractere;
            }
            else{
                if (!numero.empty()) {
                    empilhar(numero);
                    numero.clear();
                }
                empilhar(std::string(1, caractere)); // Empilha o operador ou parênteses
            }
        }
        if (!numero.empty()) {
            empilhar(numero);
        }
        
    }

};

int main(){
    Pilha p;
    p.ler_Entrada();
    p.mostrar_pilha();
}