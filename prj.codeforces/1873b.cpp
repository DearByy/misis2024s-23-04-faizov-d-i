#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int t;
    std::cin >> t;
    while (t--){
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        int pr = 1;
        int min = 1e10;
        int zeros = 0;

        for (int i = 0; i < n; i++){
            std::cin >> a[i];

            if (a[i] == 0){
                zeros++;
                min = 0;
            } else{
                pr *= a[i];
                if (a[i] < min) min = a[i];
            }
        }

        if (min > 0) {
            pr += (pr / min);
        } else if (zeros > 1){
            pr = 0;
        }

        std::cout << pr << std::endl;

    }
}
