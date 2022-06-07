#include <iostream>
#include <vector>
#include <math.h>

using std::string;
using std::vector;
using std::min;
using std::max;

int lcs3(vector<int> a, vector<int> b, vector<int> c, int an, int bn, int cn) {
  vector<vector<vector<int>>> table (an + 1,
    vector<vector<int>>(bn + 1,
      vector<int>(cn + 1)));

  for(int i = 0; i <= an; ++i) {
    for(int j = 0; j <= bn; ++j) {
      for(int k = 0; k <= cn; ++k) {
        if (i == 0 || j == 0 || k == 0) 
          table[i][j][k] = 0;

        else if (a[i-1] == b[j-1] && a[i-1] == c[k-1])
          table[i][j][k] = table[i-1][j-1][k-1] + 1;

        else 
          table[i][j][k] = max(max(table[i-1][j][k], table[i][j-1][k]), table[i][j][k-1]);
      }
    }
  } 

  return table[an][bn][cn];
}

int main() {
  int an, bn, cn;

  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c, an, bn, cn) << std::endl;
}
