#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>

bool F(){

    int n, min_i;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i){
        std::cin >> a[i];
        b[i] = a[i];
    }
    

    sort(b.begin(), b.end());

    for(int i = 0; i < n; ++i){
        if(a[i] % 2 != (b[i] % 2)) return false;
    }
    return true;

}

int main(){

    int t;
    std::cin >> t;
    while (t--){
       if(F()){
        std::cout << "YES" << std::endl;
       } else{
        std::cout << "NO" << std::endl;
       }
    }

}
