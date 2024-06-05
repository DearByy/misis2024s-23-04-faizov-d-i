#include <iostream>
#include <array>

int main (){
    int t = 0;
    std::cin >> t;
    for (int j = 0;j<t;j++){
        int n = 0;
        int m = 100000000;
        std::cin >> n;
        std::array <int, 100> a;
        for (int i = 0;i<n;i++){
            int k = 0;
            std::cin >> k;
            a[i] = k;
            if (k<m){
                m = k;
            }
        }
        int sum = 0;
        for (int i = 0;i<n;i++){
            sum = sum + a[i] - m;
        }  
        std::cout << sum << std::endl;     

    }


    return 0;
}