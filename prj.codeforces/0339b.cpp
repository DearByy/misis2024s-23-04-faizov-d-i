#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void F(){
    long long n, m, s = 0;
    std::cin >> n >> m;
    std::vector<long long> a(m);
    for (long long i = 0; i < m; i++){
        std::cin >> a[i];
    }

    s += a[0] - 1;

    for (long long i = 1; i < m; i++){
        if (a[i - 1] <= a[i]){
            s += a[i] - a[i - 1];
        } else{
            s += n - a[i - 1] + a[i];
        }
    }
    std::cout << s << std::endl;
}

int main(){
    F();
}
