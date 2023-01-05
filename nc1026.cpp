#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;
    if (n == 1) {
        std::cout << 1;
        return 0;
    }
    std::vector<long long> vll(n);
    for (int t = 0; t < n; ++t)
        std::cin >> vll[t];
    std::sort(vll.begin(), vll.end());
    auto iter = vll.begin() + 1;
    int r = 1;
    while (iter != vll.end()) {
        if (std::abs(*iter - *(iter - 1)) > m)
            ++r;
        ++iter;
    }
    std::cout << r;
    return 0;
}
