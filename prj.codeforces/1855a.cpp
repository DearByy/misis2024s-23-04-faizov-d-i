#include <iostream>
#include <vector>

void F(){

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i){
        std::cin >> a[i];
    }

    int ans;
    ans = 0;
    for (int i = 0; i < n; ++i){
        if (a[i] == i + 1){
            ans += 1;
        }
    }
    std::cout << (ans + 1) / 2 << std::endl;

}

int main(){

    int t;
    std::cin >> t;
    while (t--){
        F();
    }

}
