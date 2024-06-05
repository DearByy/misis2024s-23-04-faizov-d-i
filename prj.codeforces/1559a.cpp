#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

void F(){

    int n;
    std::cin >> n;
    std::vector<int>a(n);
    for (int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    int x = a[0];
    for (int i = 1; i < n; i++){
        x &= a[i];
    }

    std::cout << x << std::endl;
    
}

int main(){

    int t;
    std::cin >> t;
    while (t--){
        F();
    }
}
