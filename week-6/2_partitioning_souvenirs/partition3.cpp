#include <iostream>
#include <vector>

using std::vector;

bool subset_sum(vector<int> &A, int n, int a, int b, int c) {
  if (a == 0 && b == 0 && c == 0) return true;

  if (n < 0) return false;

  bool s1 = false;
  if (a - A[n] >= 0)
    s1 = subset_sum(A, n - 1, a - A[n], b, c);
    
  bool s2 = false;
  if (!s1 && b - A[n] >= 0)
    s2 = subset_sum(A, n - 1, a, b - A[n], c);
    
  bool s3 = false;
  if (!s1 && !s2 && c - A[n] >= 0)
    s3 = subset_sum(A, n - 1, a, b, c - A[n]);

  return s1 || s2 || s3;
}

int partition3(vector<int> &A) {
  int sum;
  for (int i = 0; i <= A.size(); ++i)
    sum += A[i];

  if (sum % 3 != 0) return 0;

  sum /= 3;
  int n = A.size();

  vector<vector<vector<int>>> dp (n + 1, vector<vector<int>>(sum + 1, vector<int>(sum)));

  for (int i = 0; i <= n; ++i)
  for (int j = 0; j <= sum; ++j)
  for (int k = 0; k <= sum; ++k) {
    if (i == 0 || j == 0 || k == 0) dp[i][j][k] = 0;

    else if (A[i-1] > j) 
  }
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
