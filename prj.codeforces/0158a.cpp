#include <iostream>
#include <string>
#include <vector>
#include <sstream>
 
int main() {
    int n, k;
    std::cin >> n >> k;
 
    std::vector<int> scores(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> scores[i];
    }
    int winners;
    for (int i = 0; i < n; i++)
    {
        if (scores[i] >= scores[k - 1] && scores[i] > 0)
        {
            winners++;
        }
    }
    std::cout << winners;
}
