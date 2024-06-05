#include <iostream>

int main(){
    int t;
    std::cin >> t;
    while (t--){
        std::string s;
        std::cin >> s;

        if(s[0] == 'a' || s[1] == 'b' || s[2] == 'c'){
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
}
