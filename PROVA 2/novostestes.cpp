#include <iostream>

int main(){
int *v = new int[2]{1,4};
int *v2 = v;
for(int i=0; i<2;i++){
    std::cout << v2[i] << " ";
}
v[0]=8;
for(int i=0; i<2;i++){
    std::cout << v2[i] << " ";
}
v2[1]=7;//caraca, modifica mesmo!
for(int i=0; i<2;i++){
    std::cout << v2[i] << " ";
}
}