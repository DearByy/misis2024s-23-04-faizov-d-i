#include <iostream>
#include <algorithm>

int s = 10;

int points(int row, int col){
    if (row > s/2) row = s - row + 1;
    if (col > s/2) col = s - col + 1;
    return std::min(row, col);
}

int main(){
    int t;
    std::cin >> t;
    while (t--) {

        int score = 0;

        for (int i = 1; i <= s; i++){
            std::string x;
            std::cin >> x;
            for(int j = 0; j < s; j++){
                if (x[j] == 'X') {
                    score += points (i, j + 1);
                }
            }
        }
    std::cout << score << std::endl;
    }
}
