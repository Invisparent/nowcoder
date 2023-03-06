#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long n, s;
    std::cin >> n >> s;
    long long avg = s / n;
    long long rem = s - avg * n;
    for (auto t = rem; t < n; ++t)
        std::cout << avg << ' ';
    for (int t = 0; t < rem; ++t)
        std::cout << avg + 1 << ' ';
    return 0;
}
