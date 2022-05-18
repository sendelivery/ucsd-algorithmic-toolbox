#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using std::vector;

int binary_search(const vector<int> &a, int x, int min, int max)
{
  if (max < min)
    return -1;

  int mid = min + ((max - min) / 2);

  if (a[mid] == x) {
    return mid;
  }
  else if (a[mid] > x) {
    return binary_search(a, x, min, (mid - 1));
  }
  else {
    return binary_search(a, x, (mid + 1), max);
  }
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x)
      return i;
  }
  return -1;
}

int main() {
  // stress test
  // bool flag = true;
  // while (flag)
  // {
  //   // generate a random input array of size 1..n
  //   int n = rand() % 1000 + 1; // 1 to 1000
  //   std::cout << n << "\n";
  //   vector<int> a(n);
  //   for (int i = 0; i <= n; ++i)
  //   {
  //     a[i] = i + 500; // 500..1500 at max
  //   }

  //   std::cout << "Input array: " << a[0] << " < x < " << a[n - 1] << "\n";

  //   // generate random numbers to test
  //   int m = 100;
  //   std::cout << m << " Tests:\n";
  //   vector<int> b(m);
  //   for (int i = 0; i < m; ++i)
  //   {
  //     b[i] = 520; /* rand() % 42 + 501; */
  //     std::cout << b[i] << " ";
  //   }

  //   std::cout << "\n";

  //   for (int i = 0; i < m; ++i)
  //   {
  //     int res = binary_search(a, b[i], 0, n),
  //         res1 = linear_search(a, b[i]);

  //     std::cout << "Test: " << b[i] << ", " << res << " " << res1 << " ";
  //     if (res != res1)
  //     {
  //       std::cout << "WRONG" << std::endl;
  //       flag = false;
  //       break;
  //     }

  //     std::cout << "OK\n";
  //   }
  // }

  // return 0;

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
    std::cout << binary_search(a, b[i], 0, a.size() - 1) << ' ';
  }
}
