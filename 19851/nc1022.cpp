#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    while (std::cin >> n) {
        std::vector<int> vi(n);
        int minVal = 1000;
        for (int t = 0; t < n; ++t) {
            std::cin >> vi[t];
            if (vi[t] < minVal)
                minVal = vi[t];
        }
        long long r = 0;
        std::for_each(vi.begin(), vi.end(), [&](const int &ini) {
            r += ini - minVal;
        });
        std::cout << r << ' ' << minVal + r << std::endl;
    }
    return 0;
}
