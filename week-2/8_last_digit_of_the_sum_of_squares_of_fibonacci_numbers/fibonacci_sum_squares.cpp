#include <iostream>
using namespace std;

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

unsigned long long fibonacci_sum_squares_fast(long long n) {
    if (n <= 1)
        return n;

    n = n % 60;
    if (n == 0) 
        return 0;

    long long previous = 0;
    long long current  = 1;
    unsigned long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int main() {
    long long n;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
