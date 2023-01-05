#include <iostream>
#include <vector>
#include <algorithm>

// 仔细想想，用最大的纸牌压最小的纸牌就是最优解——这是为什么呢？

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> vllA(n), vllB(n);
    for (int t = 0; t < n; ++t)
        std::cin >> vllA[t];
    for (int t = 0; t < n; ++t)
        std::cin >> vllB[t];
    std::sort(vllA.begin(), vllA.end());
    std::sort(vllB.begin(), vllB.end(), std::greater<>());
    long long r = 0;
    for (int t = 0; t < n; ++t)
        if (vllB[t] > vllA[t])
            r += vllB[t] - vllA[t];
    std::cout << r;
    return 0;
}
