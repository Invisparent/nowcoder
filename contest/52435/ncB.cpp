#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long n;
    std::cin >> n;

    std::vector<long long> data(n);
    for (auto t = 0; t < n; ++t)
        std::cin >> data[t];

    std::sort(data.begin(), data.end());
    long long res = 0;
    for (int t = 0; t < n; ++t)
        res += data[t] * (n - t);

    std::cout << res;
    return 0;
}
