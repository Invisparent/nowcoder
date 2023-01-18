// https://ac.nowcoder.com/acm/contest/24213/1004
// 数字三角形

// 就这???

#include <cstdio>

int main() {
    int n;
    std::scanf("%d", &n);
    int col = 1, pn = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < col; ++j) {
            std::printf("%4d", pn++);
        }
        std::printf("\n");
        ++col;
    }
    return 0;
}
