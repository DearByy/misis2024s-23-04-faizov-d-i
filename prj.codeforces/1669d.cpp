#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void F(){
    int n;
    std::string picture;
    std::cin >> n >> picture;
    std::string answer = "YES";

    picture = 'W' + picture + 'W';
    n += 2;

    bool hasR = false;
    bool hasB = false;

    for (int i = 1; i < n; ++i){
        char item = picture[i];
        char previous = picture[i - 1];
        if (item == 'W'){
            if (previous != 'W') {
                if(!hasR || !hasB){
                    answer = "NO";
                }
            }
        }
        else {
            if (previous == 'W'){
                hasB = false;
                hasR = false;
            }
            if (item == 'R'){
                hasR = true;
            }
            else{
                hasB = true;
            }
        }
    }
    
    std::cout << answer << std::endl;
}

int main(){
    int t;
    std::cin >> t;
    while(t--){
        F();
    }
}
