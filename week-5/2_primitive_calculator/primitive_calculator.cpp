#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using std::vector;

vector<int> optimal_sequence(int n)
{
  std::vector<int> sequence;
  while (n >= 1)
  {
    sequence.push_back(n);
    if (n % 3 == 0)
    {
      n /= 3;
    }
    else if (n % 2 == 0)
    {
      n /= 2;
    }
    else
    {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> dp_sequence(int n)
{
  vector<int> v(n + 1, 0);
  v[1] = 0;
  v[2] = 1;
  v[3] = 1;

  for (int i = 4; i < n + 1; ++i) {
    int min = INT8_MAX;
    if (i % 3 == 0) {
      // odd and divisible by 3?
      min = v[i/3] < min ? v[i/3] : min;
    } else if (i % 2 == 0) {
      // even and divisible by 2?
      min = v[i/2] < min ? v[i/2] : min;
    }
    min = v[i-1] < min ? v[i-1] : min;
    
    v[i] = min + 1;
  }

  vector<int> sequence;
  while (n > 1) {
    sequence.push_back(n);
    if (v[n-1] == v[n] - 1) --n;
    else if (n % 2 == 0 && v[n/2] == v[n] - 1) n /= 2;
    else if (n % 3 == 0 && v[n/3] == v[n] - 1) n /= 3;
  }
  sequence.push_back(1);
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> sequence = dp_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i)
  {
    std::cout << sequence[i] << " ";
  }
}
