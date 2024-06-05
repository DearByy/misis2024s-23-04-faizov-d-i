#include <iostream>
#include <vector>

void F(){

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i){
        std::cin >> a[i];
    }

    int s;
    s = 0;
    for(int i = 0; i < n; ++i){
        if (a[i] % 2 != 0);
        s += 1;
    }

    if (s % 2 != 0){
        std::cout << "NO" << std::endl;
    } else{
        std::cout << "YES" << std::endl;
    }
}

int main(){

    int t;
    std::cin >> t;
    while (t--){
        F();
    }

}
