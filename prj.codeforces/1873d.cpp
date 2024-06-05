#include <iostream>

int main(){
    int t;
    std::cin >> t;
    while (t--){
        int n, k;
        std::cin >> n >> k;
        std::string s;
        std::cin >> s;

        int idx = 0;
        int cnt = 0;

        while (idx < n) {
            if (s[idx] == 'B') {
                idx += k;
                cnt++;
            } else {
                idx++;
            }
        }
        
        std::cout << cnt << std::endl;
    }
}