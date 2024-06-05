#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void F(){
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int k;
    std::cin >> k;
    int m[26];
    for (int i = 0; i < 26; i++){
        m[i] = 0;
    }
    char x;
    for (int i = 0; i < k; i++){
        std::cin >> x;
        m[x - 'a'] = 1;
    }
    int count = 0;
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (m[s[i] - 'a'] != 0){
            ans = std::max(ans, count);
            count = 1;
        } else{
            count++;
        }
    }
    std::cout << ans << std::endl;
}

int main(){
    int t;
    std::cin >> t;
    while(t--){
    F();
    }
}
