#include <iostream>


int main(){
    int t;
    double a, b, c, ans;
    std::cin >> t;
    ans = 0;
    
    while(t--){
        std::cin >> a >> b >> c;
        ans = (abs(b - a) + 2* c - 1)/ (2 * c);
        std::cout << static_cast<int> (ans)<< std::endl;
}
}
