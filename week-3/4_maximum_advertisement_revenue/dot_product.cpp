#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
  std::sort(b.begin(), b.end());
  std::sort(a.begin(), a.end());
  
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}

// n ads with a certain price per click each
// estimate the expected number of clicks per day for each ad 1..n
// distribute ads among slots to maximise revenue

// given a1..an (profit per click) and b1..bn (avg clicks on slot)
// partition them into pairs (ai,bj) such that the sum is maximised