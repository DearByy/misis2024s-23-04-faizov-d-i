#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int a[200000];
int t;

int main(){
    std::cin >> t;
    while(t--){
    int n, s = 0;
    std::cin >> n;
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }

    int ans = -1;

    std::sort(a, a + n);

    for(int j = 0; j < n - 2; ++j){
        if (a[j] == a[j + 1] && a[j] == a[j + 2]){
            ans = std::max(ans, a[j]);
        }
        }
    std::cout << ans << std::endl;
    }
}

