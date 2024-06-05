#include <iostream>
#include <vector>
#include <string>

int main(){

    int a, b, c, p;
    std::cin >> a >> c;
    b = 0;
    p = 1;

    while (a || c){
        b += ((c % 3 - a % 3 + 3) % 3) * p;
        p *= 3;
        a /= 3;
        c /= 3;
    }

    std::cout << b << std::endl;

}
