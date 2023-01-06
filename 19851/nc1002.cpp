#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string inString;
    while (std::getline(std::cin, inString)) {
        if (inString.size() == 1) {
            std::cout << "YES\n";
            continue;
        }
        bool flag = true;
        std::vector<std::vector<bool>> vvb(3, std::vector<bool>(3, false));
        std::string::const_iterator iterA = inString.begin(), iterB = inString.begin() + 1;
        int ia = *iterA - '0' - 1, xa = ia % 3, ya = ia / 3, ib, xb, yb;
        vvb[ya][xa] = true;
        while (iterB != inString.cend()) {
            ia = *iterA - '0' - 1;
            xa = ia % 3;
            ya = ia / 3;
            ib = *iterB - '0' - 1;
            xb = ib % 3;
            yb = ib / 3;
            if (vvb[yb][xb]) {
                flag = false;
                break;
            }
            if ((xa == xb && std::abs(ya - yb) == 2) || (ya == yb && std::abs(xa - xb) == 2) ||
                (std::abs(xa - xb) == 2 && std::abs(ya - yb) == 2)) {
                int xm = (xa + xb) / 2, ym = (ya + yb) / 2;
                if (!vvb[ym][xm]) {
                    flag = false;
                    break;
                }
            }
            vvb[yb][xb] = true;
            ++iterA;
            ++iterB;
        }
        std::cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}
