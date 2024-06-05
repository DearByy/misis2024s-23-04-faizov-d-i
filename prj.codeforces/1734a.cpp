#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int t;
    std::cin >> t;
    while (t--){
        int n;
        std::cin >> n;
        std::vector<long long> a(n);
        for (int i = 0; i < n; i++){
            std::cin >> a[i];
        }

        std::sort(a.begin(), a.end());
        long long mini = 1e11;
        for(int i = 0; i < n - 2; i++){
            long long x = a[i];
            long long y = a[i + 1];
            long long z = a[i + 2];
            mini = std::min(mini, (z - y) + (y - x));
        }
        std::cout << mini << "\n";

    }
}
