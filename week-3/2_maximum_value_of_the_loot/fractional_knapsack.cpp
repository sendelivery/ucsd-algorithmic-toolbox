#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  if (capacity <= 0 || weights.size() == 0) return 0;

  double value = 0.0;

  // normalise to find the max relative to its weight
  int max_index = 0;
  double max_normalised = 0.0;
  for (int i = 0; i < weights.size(); ++i) {
    double temp = (double) values[i] / (double) weights[i];
    if (max_normalised < temp) {
      max_normalised = temp;
      max_index = i;
    }
  }

  double fraction = 1.0;

  // if weight exceeds capacity, only take a fraction of most expensive spice
  if (capacity < weights[max_index]) {
    fraction = (double) capacity / (double) weights[max_index];
  }

  value = values[max_index] * fraction;
  capacity -= weights[max_index] * fraction;

  values.erase(values.begin() + max_index);
  weights.erase(weights.begin() + max_index);

  return value + get_optimal_value(capacity, weights, values);
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
