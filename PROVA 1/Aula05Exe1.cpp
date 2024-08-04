#include <iostream>
#include <string>

struct Par{
    int chave;
    std::string valor;
};

struct Dicionario{
    static constexpr int tam = 5;
    Par v[tam];
    int n; // número de pares chave-valor presentes no dicionário

    Dicionario() : n(0) {}

    bool inserir(int chave, const std::string& valor){
        if(n >= tam) return false; // dicionário cheio

        for(int i = 0; i < n; i++){
            if(v[i].chave == chave){
                // Se a chave já existir, atualize o valor
                v[i].valor = valor;
                return true;
            }
        }

        // Se a chave não existir, insira um novo par chave-valor
        v[n].chave = chave;
        v[n].valor = valor;
        n++;
        return true;
    }

    bool remover(int chave){
        for(int i = 0; i < n; i++){
            if(v[i].chave == chave){
                // Se a chave for encontrada, mova o último elemento para o lugar da chave removida
                v[i] = v[n - 1];
                n--;
                return true;
            }
        }
        return false; // chave não encontrada
    }

    std::string buscar(int chave){
        for(int i = 0; i < n; i++){
            if(v[i].chave == chave){
                return v[i].valor; // retorna o valor associado à chave
            }
        }
        return ""; // retorna uma string vazia se a chave não for encontrada
    }
};

int main(){
    Dicionario d;

    d.inserir(1, "um");
    d.inserir(2, "dois");
    d.inserir(3, "tres");
    d.inserir(4, "quatro");
    d.inserir(5, "cinco");

    std::cout << "Valor da chave 3: " << d.buscar(3) << std::endl;

    d.remover(3);

    std::cout << "Valor da chave 3 apos remocao: " << d.buscar(3) << std::endl;

    return 0;
}
 