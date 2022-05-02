#include <iostream>

long long get_pisano_period(long long m) {
    long long previous = 0, current = 1, result = 0;

    for (long long i = 0; i <= m * m; ++i) {
        long long tmp_previous = current;
        current = (previous + current) % m;
        previous = tmp_previous;

        if (previous == 0 && current == 1)
            result = i + 1;
    }

    return result;
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    long long period = get_pisano_period(m);
    n = n % period;

    if (n < 2) return n;

    long long previous = 0;
    long long current = 1;

    for(int i = 0; i < n - 1; i++)
    {
        long tmp_previous = 0;
        tmp_previous = current;
        current = (previous + current) % m;
        previous = tmp_previous;
    }
    return current % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
