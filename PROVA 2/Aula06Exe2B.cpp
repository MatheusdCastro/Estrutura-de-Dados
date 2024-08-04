#include <iostream>

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
   int n;
   double x;
   std::cout <<"Digite um valor n: \n";
   std::cin >> n;
   double *v = new double [n];
   std::cout <<"Digite os "<< n <<" doubles: \n" ;
   for(int i = 0; i < n; i++){
    std::cin >> *(v+i);
   }
   std::cout << "Digite um valor x: \n";
   std::cin >> x;
    std::cout <<"Quantidade de elementos restantes no vetor: "<<remover_ocorrencias(v,n,x)<<'\n';
   for(int i = 0; i < n; i++){
    std::cout <<*(v+i)<<" ";
    }
    delete[] v;
}