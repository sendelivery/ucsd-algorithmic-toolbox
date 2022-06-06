#include <iostream>
#include <vector>

int get_change(int m)
{
  if (m < 0)
    return 0;
  std::vector<int> d = {1, 3, 4};
  std::vector<int> change(m + 1, INT8_MAX);
  change[0] = 0; // 0 coins used to change 0
  int numCoins;

  for (int i = 1; i < change.size(); ++i)
  {
    for (int j = 0; j < d.size(); ++j)
    {
      if (i >= d[j])
      {
        numCoins = change[i - d[j]] + 1;
        if (numCoins < change[i])
        {
          change[i] = numCoins;
        }
      }
    }
  }
  return change[m];
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
