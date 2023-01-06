#include <iostream>
#include <iomanip>
#include <set>

int main() {
    std::cout << std::fixed << std::setprecision(1);
    int T;
    std::cin >> T;
    int n, m;
    while (std::cin >> n >> m) {
        std::multiset<int, std::greater<>> ms;
        int chairNum = 0;
        int itmp;
        for (int t = 0; t < n; ++t) {
            std::cin >> itmp;
            ms.insert(itmp);
            std::cin >> itmp;
            if (itmp)
                ++chairNum;
        }
        int discountNum = std::min(std::min(m, n), chairNum), t = 0;
        double r = 0;
        for (const int &i: ms) {
            if (t < discountNum) {
                r += i / 2.0;
                ++t;
            } else
                r += i;
        }
        std::cout << r << std::endl;
    }
    return 0;
}
