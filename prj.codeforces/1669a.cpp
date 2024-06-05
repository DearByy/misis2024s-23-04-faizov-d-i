#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

void F(){
    int n;
    std::cin >> n;
    if (n <= 1399) std::cout << "Division 4" << std::endl;
    else if (n >= 1400 && n <= 1599) std::cout << "Division 3" << std::endl;
    else if (n >= 1600 && n <= 1899) std::cout << "Division 2" << std::endl;
    else std::cout << "Division 1" << std::endl;
}

int main(){
    int t;
    std::cin >> t;
    while(t--){
        F();
    }
}
