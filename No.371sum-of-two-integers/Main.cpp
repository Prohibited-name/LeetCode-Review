#include <iostream>

int main(){
    int a,b;
    std::cin >> a >> b;
    unsigned int normal_bit = a ^ b;
    unsigned int carry_bit = ((unsigned int)a & b) << 1;
    while(carry_bit){
        a = normal_bit;
        b = carry_bit;
        normal_bit = a ^ b;
        carry_bit = ((unsigned int)a & b) << 1;
    }
    std::cout<<normal_bit;
}