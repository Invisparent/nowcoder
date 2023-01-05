#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int T;
    std::cin >> T;
    int n, k;
    while (std::cin >> n >> k) {
        std::vector<int> vi(n);
        for (int t = 0; t < n; ++t)
            std::cin >> vi[t];
        if (n == 1) {
            std::cout << 1 << std::endl;
            continue;
        }
        std::sort(vi.begin(), vi.end());
        int max = 0;
        auto iterA = vi.begin(), iterB = vi.begin() + 1;
        while (iterB != vi.end()) {
            if (*iterB - *iterA <= k) {
                if (iterB - iterA > max)
                    max = iterB - iterA;
                ++iterB;
            } else
                ++iterA;
        }
        std::cout << max + 1 << std::endl;
    }
    return 0;
}
