#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_fast(int a, int b) {
  long long x1 = a, x2 = b;
  // calculate gcd
  int remainder;
  while (a % b > 0) {
    remainder = a % b;
    a = b;
    b = remainder;
  }

  // multiple each term by the other, over its gcd
  return (x1 * x2) / b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
