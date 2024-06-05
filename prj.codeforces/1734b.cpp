#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    int t;
    std::cin >> t;
    while (t--){
        int n;
        std::cin >> n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                if (j == 1 || j == i) {
                    std::cout << 1 << " ";
                    } else {
                    std::cout << 0 << " ";
                    }
            }
            std::cout << "\n";
        }
    }
}