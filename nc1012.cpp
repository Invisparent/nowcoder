#include <iostream>
#include <vector>

int main() {
    std::vector<long long> vi{1, 2};
    for (int t = 3; t <= 80; ++t)
        vi.push_back(vi[t - 2] + vi[t - 3]);
    int i;
    std::cin >> i;
    while (std::cin >> i)
        std::cout << vi[i - 1] << std::endl;
    return 0;
}
