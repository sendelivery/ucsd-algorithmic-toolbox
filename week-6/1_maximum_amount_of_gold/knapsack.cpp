#include <iostream>
#include <vector>
#include <math.h>

using std::vector;
using std::max;

int optimal_weight(int W, const vector<int> &wt) {
  int n = wt.size();
  vector<vector<int>> dp(n + 1, vector<int>(W + 1));

  for (int i = 0; i <= n; ++i) {
    for (int w = 0; w <= W; ++w) {
      if (i == 0 || w == 0) // first column and row = 0
        dp[i][w] = 0;

      else if (wt[i - 1] <= w) // if weight (value) of the previous items fits, compare to find max for subproblem
        dp[i][w] = max(
          wt[i-1] + dp[i-1][w-wt[i-1]],
          dp[i-1][w]
        );

      else // else the weight (value) is that of the item.
        dp[i][w] = dp[i-1][w];
    }
  }

  return dp[n][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
