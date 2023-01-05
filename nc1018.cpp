#include <iostream>
#include <vector>

int main() {
    int n;
    std::vector<long long> vll{0, 0, 1, 1};
    vll.resize(51);
    for (int t = 4; t <= 50; ++t)
        vll[t] = vll[t - 1] + vll[t - 2] + vll[t - 3];
    while (std::cin >> n)
        std::cout << vll[n] << std::endl;
    return 0;
}
