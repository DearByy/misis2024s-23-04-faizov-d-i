#include <iostream>
#include <vector>
#include <string>

int main(){
  int t;
  std::cin >> t;

  while (t--){
    int n;
    std::cin >> n;
    std::vector<int> array;
    int p = 1;
    while (n > 0){
      if (n % 10 > 0){
        array.push_back((n % 10) * p);
      }
      n /= 10;
      p *= 10;
      }
      std::cout << array.size() << "\n";
      for (int i = 0; i < array.size(); i++){
        std::cout << array[i] << " ";
      }
    }
}
