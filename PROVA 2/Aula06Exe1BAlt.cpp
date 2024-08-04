#include<iostream>
//outro jeito, sem precisar usar o m, usando só o n://

void inverter(double *p, int n){
for(int i = 0; i < n/2; i++){
    double temp = *(p+i);
    *(p+i) = *(p+(n-1-i));
    *(p+(n-i-1)) = temp;
    }
}

int main(){
    int n;
    std::cout <<"Digite um valor n: \n";
    std::cin >> n;
    if(n > 0){
        if(n <= 10){
            double *p = new double [n];//alocação dinâmica para usar o n, pq não dá pra fazer simplesmente double p[n];
            std::cout <<"Digite os "<< n << " doubles: \n";
            for(int i = 0; i < n; i++){
                std::cin >> *(p+i);
            }
            inverter(p,n);
            for(int i = 0; i < n; i++){// não dá pra usar aquele loop pq ele só funciona em arrays de tamanho fixo
                std::cout <<*(p+i)<<" ";
            }
            delete[] p;
        }
        else std::cerr <<"O valor de j deve ser mo maximo 10";
    }
    else std::cerr <<"O valor de n deve ser um inteiro positivo";
}