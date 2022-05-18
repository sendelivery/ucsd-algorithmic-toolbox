#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x, int min, int max) {
  if (max < min) return -1;
  int index = min + ((max - min) / 2);
  if(a[index] == x) {
    if(a[index-1] == x) {
          return binary_search(a, x, min, (index - 1)); 
    }
    return index;
  }
  else if(a[index] > x) {
    return binary_search(a, x, min, (index - 1));
  }
  else {
    return binary_search(a, x, (index + 1), max);
  }
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i], 0, n) << ' ';
  }
}
