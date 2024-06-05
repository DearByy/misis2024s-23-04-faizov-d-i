#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void F(){
    std::string s, sorted_str, res = " ";
    std::cin >> s;

    for (int i = 0; i < s.size(); i += 2){
        sorted_str += s[i];
    }
    
    std::sort(sorted_str.begin(), sorted_str.end());

    for (int i = 0; i < sorted_str.size(); i++){
        res = res + sorted_str[i] + '+';
    }

    std::cout << res.substr(1, res.size() - 2) << std::endl;
}

int main(){
    F();
}
