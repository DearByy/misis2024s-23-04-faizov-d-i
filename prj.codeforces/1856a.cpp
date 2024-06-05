#include <iostream>
#include <vector>
#include <string>

int main(){
    int t;
    std::cin >> t;

    while (t--){
        int n;
        std::cin >> n;
        
        std::vector<int> a(n);
        for(int i = 0; i < n; ++i){
            std::cin >> a[i];
        }

        int ans = 0;
        for (int i = 0; i < n - 1; i++){
            if (a[i] > a[i + 1]){
                ans = std::max(ans, a[i]);
        }
    }

    std::cout << ans << std::endl;
}
}
