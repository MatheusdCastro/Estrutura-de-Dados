#include <iostream>
using namespace std;
static constexpr int n = 5;

void inverter(double *p, int n){
for(int i = 0; i < n/2; i++){
    double temp = p[i];
    p[i] = p[n-1-i];
    p[n-i-1] = temp;
}

}
int main(){
double p[n]{3,4,8,10,73};
inverter(p,n);
for(double P_elem : p){
    cout <<P_elem<<" ";
    }
}
