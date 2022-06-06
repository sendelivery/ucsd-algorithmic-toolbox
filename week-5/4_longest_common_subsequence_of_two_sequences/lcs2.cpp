#include <iostream>
#include <vector>
#include <math.h>

using std::string;
using std::vector;
using std::min;
using std::max;

int lcs2(string a, string b, int n, int m) {
  vector<vector<int>> table(n + 1, vector<int>(m + 1, 0));

  for(int i = 0; i <= n; ++i) {
    for(int j = 0; j <= m; ++j) {
      if (i == 0 || j == 0) 
        table[i][j] = 0;

      else if (a[i-1] == b[j-1])
        table[i][j] = table[i-1][j-1] + 1;

      else 
        table[i][j] = max(table[i-1][j], table[i][j-1]);
    }
  } 

  return table[n][m];
}

int main() {
  int num;
  string a = "", b = "";

  size_t n;
  std::cin >> n;
  for (size_t i = 0; i < n; i++) {
    std::cin >> num;
    a += num;
  }

  size_t m;
  std::cin >> m;
  for (size_t i = 0; i < m; i++) {
    std::cin >> num;
    b += num;
  }

  std::cout << lcs2(a, b, n, m) << std::endl;
}
