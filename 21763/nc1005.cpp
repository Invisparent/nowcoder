// https://ac.nowcoder.com/acm/contest/21763/1005

#include <iostream>
#include <vector>
#include <algorithm>

inline int fread() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}


int main() {
    int T = fread();
    int n, k;
    for (int x = 0; x < T; ++x) {
        n = fread();
        k = fread();
        std::vector<int> vi(n);
        for (int t = 0; t < n; ++t)
            vi[t] = fread();
        std::sort(vi.begin(), vi.end());
        std::cout << vi[k - 1] << std::endl;
    }
}
