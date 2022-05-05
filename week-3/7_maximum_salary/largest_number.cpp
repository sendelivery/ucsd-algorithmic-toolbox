#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::stoi;

bool is_greater_or_equal(string a, string b) {
  if(stoi(a+b) >= stoi(b+a))
    return true;
  else
    return false;
}

string largest_number(vector<string> a) {
  string answer;

  while(a.size() > 0)  {
    string max_num = "0";
    int max_index;
    for (int i = 0; i < a.size(); ++i) {
      if(is_greater_or_equal(a[i], max_num)) {
        max_num = a[i];
        max_index = i;
      }
    }
    answer.append(max_num);
    a.erase(a.begin() + max_index);
  }

  return answer;

  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
