#include <iostream>
#include <vector>

using std::vector;

int merge(vector<int> &a, size_t left, size_t mid, size_t right) {
  int sub_size = mid - left + 1;
  int sub1_size = right - mid;
  int inversions = 0;

  vector<int> sub(sub_size);
  vector<int> sub1(sub1_size);

  for (int i = 0; i < sub_size; ++i)
    sub[i] = a[left + i];
  for (int i = 0; i < sub1_size; ++i)
    sub1[i] = a[mid + 1 + i];

  int sub_index = 0, sub1_index = 0, merged_index = left;

  while (sub_index < sub_size && sub1_index < sub1_size) {
    if (sub[sub_index] <= sub1[sub1_index]) {
      a[merged_index] = sub[sub_index];
      ++sub_index;
    } else {
      a[merged_index] = sub1[sub1_index];
      inversions = inversions + (mid - sub_index);
      ++sub1_index;
    }
    ++merged_index;
  }

  while (sub_index < sub_size) {
    a[merged_index] = sub[sub_index];
    ++merged_index;
    ++sub_index;
  }

  while (sub1_index < sub1_size) {
    a[merged_index] = sub1[sub1_index];
    ++merged_index;
    ++sub1_index;
  }

  return inversions;
}

int  merge_sort(vector<int> &a, size_t left, size_t right) {
  if (left >= right) return 0;

  int mid = left + (right - left) / 2;
  int inversions = merge_sort(a, left, mid);
  inversions += merge_sort(a, mid + 1, right);

  inversions += merge(a, left, mid, right);

  return inversions;
}  

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int inversions = merge_sort(a, 0, a.size() - 1);
  inversions = inversions != 0 ? inversions + 1 : 0;
  std::cout <<  inversions << '\n';
  return 0;
}
