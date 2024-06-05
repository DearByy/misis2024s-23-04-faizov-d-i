#include <iostream>
#include <string>

void F(){
int t = 0, x = 0, y = 0, count = 0, f = 0;
std::cin >> t;
std::string st;
std::string st0;
std::cin >> st;
for (int i = 0; i < t; i++) {
    st0 = st[i];
    if (st0 == "U") {
      y += 1;
    }
    else {
      x += 1;
    }
    if (x > y) {
      if (f == 1 && i != 0) {
        f = 0;
        count += 1;
      }
      else {
        f = 0;
      }
    }
    else if (y > x) {
      if (f == 0 && i != 0) {
        f = 1;
        count += 1;
      }
      else {
        f = 1;
      }
    }
  }
std::cout << count;
}

int main() {
  F();
}
