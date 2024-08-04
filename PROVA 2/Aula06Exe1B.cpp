#include <iostream>

void inverter(double *p, int m){
for(int i = 0; i < m/2; i++){
    double temp = *(p+i);
    *(p+i) = *(p+(m-1-i));
    *(p+(m-i-1)) = temp;
    }
}

int main(){
    constexpr int n = 10;//limitando logo tamanho máximo do vetor
    int m;// tendo q usar o m para "mentir" para o usuário, fazendo ele pensar que irá digitar um valor n, mas na verdade será m.
    std::cout <<"Digite um valor n: \n";
    std::cin >> m;
    if(m > 0){
        if(m <= 10){
            double p[n];
            std::cout <<"Digite os "<< m << " doubles: \n";
            for(int i = 0; i < m; i++){
                std::cin >> *(p+i);
            }
            inverter(p,m);
            for(int i = 0; i < m; i++){
                std::cout <<*(p+i)<<" ";
            }
        }
        else std::cerr <<"O valor de j deve ser mo maximo 10";
    }
    else std::cerr <<"O valor de n deve ser um inteiro positivo";
}