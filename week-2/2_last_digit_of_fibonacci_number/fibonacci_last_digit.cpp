#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    int fib_list[n];
    fib_list[0] = 0;
    fib_list[1] = 1;

    for (int i = 2; i <= n; ++i) 
        fib_list[i] = (fib_list[i-1] + fib_list[i-2]) % 10;

    return fib_list[n];
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    }
