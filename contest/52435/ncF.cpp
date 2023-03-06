#include <iostream>
#include <vector>

std::vector<std::vector<int>> data;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, T;
    std::cin >> n >> m >> T;
    data = std::vector<std::vector<int>>(n + 2, std::vector<int>(m + 2));


}
