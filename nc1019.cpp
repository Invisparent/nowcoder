#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int T;
    std::cin >> T;
    int n, k, s;
    std::vector<int> vi;
    while (std::cin >> n >> k >> s) {
        vi.clear();
        vi.resize(n);
        for (int t = 0; t < n; ++t)
            std::cin >> vi[t];
        std::sort(vi.begin(), vi.end(), std::greater<>());
        int sigmaPlank = 0;
        for (auto iter = vi.begin() + k - 1; iter < vi.end(); iter += k)
            sigmaPlank += *iter;
        std::cout << static_cast<long long>(sigmaPlank) * s << std::endl;
    }
    return 0;
}
