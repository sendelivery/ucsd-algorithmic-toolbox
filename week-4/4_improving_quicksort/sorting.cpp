#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

/*  [3,5,3,2,1]
    ...
    []
    []
*/
void partition3(vector<int> &a, int l, int r, int &p1, int &p2) {
  int pivot = a[l]; // 3
  p1 = l;
  p2 = r;

  // first loop, move all lower elements below pivot, increase p1
  for (int i = l; i <= r; ++i) { // 2
    if (a[i] < pivot) { // 3 < 3 f
      swap(a[i], a[p1]);
      ++p1;
    }
  }
  // second loop, move all higher elements above pivot, decrease p2
  for (int i = r; i >= l; --i) {
    if (a[i] > pivot) {
      swap(a[i], a[p2]);
      --p2;
    }
  }
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}

void quick_sort_3(vector<int> &a, int l, int r) {
  if (l >= r ) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);

  int p1, p2;
  partition3(a, l, r, p1, p2);

  quick_sort_3(a, l, p1 - 1);
  quick_sort_3(a, p2 + 1, r);

}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  // randomized_quick_sort(a, 0, a.size() - 1);
  quick_sort_3(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
