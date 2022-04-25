#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long MaxPairwiseProduct(const std::vector<long long> &numbers)
{
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first)
        for (int second = first + 1; second < n; ++second)
            if (first != second)
                max_product = std::max(max_product,
                                       numbers[first] * numbers[second]);

    return max_product;
}

long long MaxPairwiseProductFast(const std::vector<long long> &numbers)
{
    int first_index = -1, second_index = -1;
    int n = numbers.size();

    for (int i = 0; i < n; ++i)
        if (first_index == -1 || numbers[first_index] < numbers[i])
            first_index = i;

    for (int j = 0; j < n; ++j)
        if (j != first_index && (second_index == -1 || numbers[second_index] < numbers[j]))
            second_index = j;

    return numbers[first_index] * numbers[second_index];
}

int main()
{
    /* stress test
    while (true)
    {
        int n = rand() % 100 + 2;
        cout << n << "\n";
        vector<long long> a;
        for (int i = 0; i < n; ++i)
        {
            a.push_back(rand() % 1000000);
        }
        for (int i = 0; i < n; ++i)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
        long long res = MaxPairwiseProductFast(a);
        long long res1 = MaxPairwiseProduct(a);

        if (res != res1)
        {
            cout << "Wrong answer: " << res << " " << res1 << endl;
            break;
        }
        else
        {
            cout << "OK" << endl;
        }
    } 

    return 0; */

    int n;
    cin >> n;
    vector<long long> numbers(n);
    for (int i = 0; i < n; ++i)
        cin >> numbers[i];

    cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}