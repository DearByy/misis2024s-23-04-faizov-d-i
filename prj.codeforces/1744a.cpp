#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

void F(){
    int n;
    std::string b = "YES";
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i){
        std::cin >> a[i];
    }
    std::string s;
    std::cin >> s;

    std::map<int, char> m;
    for (int i = 0; i < n; ++i){
        if(m.find(a[i]) == m.end()){
            m[a[i]] = s[i];
        } else if (m[a[i]] != s[i]){
            b = "NO";
        }
    }
    std::cout << b << std::endl;
}

int main(){

    int t;
    std::cin >> t;
    while (t--){
        F();
    }
}
