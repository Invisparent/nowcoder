#include <iostream>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, a, b;
    std::cin >> n >> a >> b;
    int va = n / a, vb = 0;
    int minVal = 0x3f3f3f3f;
    while (va >= 0) {
        while (va * a + (vb + 1) * b <= n)
            ++vb;
        minVal = std::min(minVal, n - va * a - vb * b);
        --va;
    }
    std::cout << minVal;
    return 0;
}
