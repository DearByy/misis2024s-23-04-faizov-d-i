#include <iostream>
#include <vector>

int p = 201;

void F(){

    bool a[p];
    int n, x, ans;
    std::cin >> n >> x;
    for (int i = 1; i <= n + x; ++i){
        a[i] = false;
    }
    for(int i = 1; i <= n; ++i){
        int r;
        std::cin >> r;
        a[r] = true;
    }
    for(int k = n + x; k > 0; --k){
        int v = 0;
        for(int i = 1; i <= k; ++i){
            if(!a[i]){
                v++;
            }
        }
        if (v <= x){
            ans = k;
        }
        
    }
    
}

int main(){

    int t;
    std::cin >> t;
    while (t--){
        F();
    }

}
