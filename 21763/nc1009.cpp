// https://ac.nowcoder.com/acm/contest/21763/1009

#include <iostream>
#include <vector>

int main() {
    std::vector<long long> vll(26);
    vll[0] = 2;
    for (int t = 1; t < 26; ++t)
        vll[t] = 3 * vll[t - 1] + 2;
    int n;
    while (std::cin >> n)
        std::cout << vll[n - 1] << std::endl;
    return 0;
}
