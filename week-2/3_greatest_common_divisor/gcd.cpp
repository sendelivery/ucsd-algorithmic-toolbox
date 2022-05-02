#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_euclidean(int a, int b) {
  int remainder;
  while (a % b > 0) {
    remainder = a % b;
    a = b;
    b = remainder;
  }

  return b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_euclidean(a, b) << std::endl;
  return 0;
}
