#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> vi(n);
    for (int t = 0; t < n; ++t)
        std::cin >> vi[t];
    std::sort(vi.begin(), vi.end());
    long long sigma = 0, r = 0;
    for (const int &i: vi)
        sigma += i;
    for (int t = 0; t < vi.size() - 1; ++t) {
        r += sigma;
        sigma -= vi[t];
    }
    std::cout << r;
    return 0;
}
