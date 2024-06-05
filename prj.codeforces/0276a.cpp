#include <iostream>
#include <vector>

int main(){
  int n, k, f, t, ans, m;
  std::cin >> n >> k;
  m = -1e9;
  for (int i = 0; i < n; i ++){
        std::cin >> f >> t;
        if (t > k){
        ans = f - (t - k);
        } else{
            ans = f;
        if (ans > m){
            m = ans;
        }
    }
    }
  std::cout << m;
}
