#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<std::pair<int, int>> data(n);
    for (int t = 0; t < n; ++t)
        std::cin >> data[t].first >> data[t].second;

    std::sort(data.begin(), data.end(), [](const auto &a, const auto &b) {
        return (a.second - a.first) > (b.second - b.first);
    });

    long long res = 0;
    int index = 0;
    while (index < k)
        res += data[index++].second;
    while (index < data.size())
        res += data[index++].first;

    std::cout << res;

    return 0;
}
