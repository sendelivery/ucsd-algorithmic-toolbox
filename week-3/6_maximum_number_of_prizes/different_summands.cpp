#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) { // 8
  vector<int> summands;
  int next_prize = 1;

  while(n > 0) {
    if ((n - next_prize) >= (next_prize + 1)) {
      summands.push_back(next_prize);
      n -= next_prize;
      ++next_prize;
    } else {
      summands.push_back(n);
      n = 0;
    }
  }

  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}

// n candies for top k places
// higher place gets a larger number of candies
