#include <iostream>
#include <string>
#include <math.h>

int main() {
  int count = 0, position = 0, sum = 0, f = 0;
  std::string alp;
  std::string round;
  alp = "abcdefghijklmnopqrstuvwxyz";
  std::cin >> round;
  count = round.length();
  for (int i = 0; i < count; i++) {
    for (int j = 0; j < 26; j++) {
      if (alp[j] == round[i]) {
        position = j;
      }
    }
    if ((26 - f + position) <= abs(f - position) && (26 - position + f >= (26 - f + position))){
      sum += 26 - f + position;
    }
    else if ((26 - f + position) >= abs((f - position)) && (26 - position + f >= abs(f - position))){
      sum += abs(f - position);
    }
    else {
      sum += 26 - position + f;
    }
    f = position;
  }
  std::cout << sum;
}
