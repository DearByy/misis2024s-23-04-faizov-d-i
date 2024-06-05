#include <iostream>

void hemorroids(){
    int n,m,x,y,d;
    std::cin >> n >> m >> x >> y >> d;
    if(x - d <= 1 && y - d <= 1){
        std::cout << -1 << std::endl; return;}
    if(x + d >= n && y + d >= m){
        std::cout << -1 << std::endl; return;}
    if(x - d <= 1 && x + d >= n){
        std::cout << -1 << std::endl; return;}
    if(y - d <= 1 && y + d >= m){
        std::cout << -1 << std::endl; return;}
    std::cout << n + m - 2 << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while(t--){
        hemorroids();
    }
}
