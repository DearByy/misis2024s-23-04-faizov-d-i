#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int a[50];
int t;

int main(){
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;
        for (int i = 0; i < n; ++i){
            std::cin >> a[i];
        }

        std::string answer = "YES";

        int fp = a[0] % 2;
        for (int i = 0; i < n; i += 2){
            if (a[i] % 2 != fp){
                answer = "NO";
            }
        }
        
        int sp = a[1] % 2;
        for (int i = 1; i < n; i += 2){
            if (a[i] % 2 != sp){
                answer = "NO";
            }
        }

        std::cout << answer << std::endl;
    }
}
