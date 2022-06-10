#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <climits>

using std::vector;
using std::string;
using std::max;
using std::min;

typedef long long int ll;

ll eval(ll a, ll b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    return 0;
  }
}

ll get_maximum_value(const string &exp) {
  int n = exp.size();
  n = (n + 1) / 2;

  ll m[n][n];
  ll M[n][n];

  memset(m, 0, sizeof(m));
	memset(M, 0, sizeof(M));

  for (int i = 0; i < n; i++) {
		m[i][i] = stoll(exp.substr(2 * i, 1));
		M[i][i] = stoll(exp.substr(2 * i, 1));
	}

  for (int i = 0; i < n - 1; ++i)
  for (int j = 0; j < n - i - 1; ++j) {
    int k = i + j + 1;
    ll min_val = LLONG_MAX;
    ll max_val = LLONG_MIN;

    for (int l = j; l < k; ++l) {
      ll a = eval(m[j][l], m[l+1][k], exp[2 * l + 1]);
      ll b = eval(m[j][l], M[l+1][k], exp[2 * l + 1]);
      ll c = eval(M[j][l], m[l+1][k], exp[2 * l + 1]);
      ll d = eval(M[j][l], M[l+1][k], exp[2 * l + 1]);

      min_val = min(min_val, min(a, min(b, min(c, d))));
      max_val = max(max_val, max(a, max(b, max(c, d))));
    }
    m[j][k] = min_val;
    M[j][k] = max_val;
  }
  
  return M[0][n - 1];
}

int main() {
  string s;
  std::cin >> s;

  std::cout << get_maximum_value(s) << std::endl;
}

// 5-8+7*4-8+9