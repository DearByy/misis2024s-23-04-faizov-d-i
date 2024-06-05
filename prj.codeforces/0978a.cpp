#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    int n;
    std::cin>> n;
    std::vector<int> a(n), res;
    std::vector<bool> used(1001,false);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for(int i = n - 1; i >= 0; i--){
        if(!used[a[i]]){
            res.push_back(a[i]);
            used[a[i]] = true;
        }
    }
    std::reverse(res.begin(),res.end());
    std::cout << res.size() << std::endl;
    for (int i = 0; i < res.size(); i++){
        std::cout<< res[i] << " ";
    }
}
