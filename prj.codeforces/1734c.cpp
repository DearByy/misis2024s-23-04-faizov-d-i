#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int t;
    std::cin >> t;
    while(t--){
        long long n;
        std::string s;
        std::cin >> n >> s;

        long long ans = 0;
        std::string marked(n, '1');

        for(long long i = 0; i < n; i++){
            if(s[i] == '0'){
                for(long long j = i + 1; j <= n; j += i + 1){
                    if(s[j - 1] == '1'){
                        break;}
                    if(marked[j - 1] == '0'){
                        continue;}
                    
                    marked[j - 1] = '0';
                    ans += i + 1;
                }
            }
        }

        std::cout << ans << std::endl;
    }
}