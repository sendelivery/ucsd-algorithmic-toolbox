#include <iostream>
#include <vector>
using std::vector;

long long fibonacci_sum_fast(long long n) {
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;

    if (n == 0) 
        return 0;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 2; i <= n; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum;
}

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    from = from % 60;
    to = from + (to-from) % 60;

    long long res = fibonacci_sum_fast(to) - fibonacci_sum_fast(from - 1);
    return res % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
