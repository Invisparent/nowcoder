#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int i;
    std::cin >> i;
    if (i == 1) {
        std::cout << 0;
        return 0;
    }
    std::vector<int> vi(i);
    for (int t = 0; t < i; ++t)
        std::cin >> vi[t];
    std::sort(vi.begin(), vi.end(), std::greater<>());
    auto iter = vi.begin() + 1;
    long long prev = vi.front(), r = 0;
    while (iter != vi.end()) {
        r += *iter * prev;
        prev += *iter;
        ++iter;
    }
    std::cout << r;
    return 0;
}
