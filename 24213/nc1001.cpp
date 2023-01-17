// https://ac.nowcoder.com/acm/contest/24213/1001
// 方块与收纳盒

#include <iostream>
#include <vector>

int main() {
    std::vector<long long> dat(81);
    dat[1] = 1;
    dat[2] = 2;
    for (int t = 3; t <= 80; ++t)
        dat[t] = dat[t - 1] + dat[t - 2];
    int n;
    std::cin >> n;
    while (std::cin >> n)
        std::cout << dat[n] << std::endl;
    return 0;
}
