#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::map;

int check_majority_element(vector<int> &a, int n) {
  map<int, int> map;
  for (int i = 0; i < n; ++i) {
    map[a[i]]++;
  }
  for (int i = 0; i < n; ++i) {
    if (map[a[i]] > (n/2)) return true;
  }

  return false;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << check_majority_element(a, a.size()) << '\n';
}
