#include <iostream>
#include <algorithm>
#include <vector>

int s = 1e10;

void F(){
    int n, k, m = s;
    std::string str;
    std::cin >> n >> k;
    std::cin >> str;
    std::vector<int> a(n + 1);

    for (int i = 1; i <= n; ++i){
        a[i] = a[i - 1] + int(str[i - 1] == 'W');
    }
    for(int i = 1; i <= n - k + 1; ++i){
        m = std::min(m, a[i + k - 1] - a[i - 1]);
    }
     std::cout << m << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while(t--){
        F();
    }
}
