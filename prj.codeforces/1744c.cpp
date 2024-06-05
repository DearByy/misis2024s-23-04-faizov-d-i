#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>


void F(){
    int n;
    char c;
    std::string s;
    std::cin >> n >> c >> s;
    s += s;
    int maxi = 0, cnt = 0;
    for (int i = 0; i  < s.size(); ++i){
        if(s[i] == c){
            cnt = 0;
            while (s[i] != 'g' && i < s.size()){
                cnt++;
                i++;
            }
            if (cnt > maxi) maxi = cnt;
        }
    }
    std::cout << maxi << std::endl;
}

int main(){
    int t;
    std::cin >> t;
    while(t--){
        F();
    }
}
