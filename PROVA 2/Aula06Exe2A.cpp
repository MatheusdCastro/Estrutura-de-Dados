#include <iostream>

static constexpr int n =5;

int remover_ocorrencias(double *v, int n, double x){
    int j = 0;
    for(int i = 0; i < n; i++){
        if(*(v+i) == x){
            *(v+i) = '?';//em int é 63
            j++;
        }
    }
    return n-j;
}

int main(){
    double v[n]{1.3,20,8,1.3,2.3};
    double x = 1.3;
    std::cout <<"Quantidade de elementos restantes no vetor: "<<remover_ocorrencias(v,n,x)<<'\n';
    for(double V_elem : v){
        std::cout <<V_elem<<" ";
    }
}