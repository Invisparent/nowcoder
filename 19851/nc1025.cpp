#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int w, n;
    std::cin >> w >> n;
    if (n == 1) {
        std::cout << 1;
        return 0;
    }
    std::vector<int> vi(n);
    for (int t = 0; t < n; ++t)
        std::cin >> vi[t];
    std::sort(vi.begin(), vi.end());
    auto iterA = vi.begin(), iterB = vi.end() - 1;
    int r = 0;
    while (iterA < iterB) {
        if (*iterA + *iterB <= w) {
            ++iterA;
            --iterB;
            ++r;
        } else {
            --iterB;
            ++r;
        }
    }
    if (iterA == iterB)
        ++r;
    std::cout << r;
    return 0;
}
