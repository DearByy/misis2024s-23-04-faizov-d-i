#include <iostream>
#include <vector>

int main() {
    int n, ans;
    std::cin >> n;
    std::vector<char> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n - 2; i++){
        if (a[i] == 'x' && a[i + 1] == 'x' && a[i + 2] == 'x'){
            ans++;
        }
    }
    std::cout << ans << std::endl;
}
