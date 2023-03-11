#include <iostream>
#include <vector>
#include <map>
#include <utility>

#define IVS_N 100005

int n, tt;
int processed;

// dst, cost
std::vector<std::pair<int, int>> data(IVS_N);
std::vector<int> dst(IVS_N, 0x3f3f3f3f);

// In Dijkstra:
// node, cost
struct Comp {
    inline bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b) const {
        return a.second < b.second;
    }
};

std::map<int, int, Comp()> x();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> tt;
    int a, b, c;
    for (int t = 0; t < tt; ++t) {
        std::cin >> a >> b >> c;
        data[b].first = c;
        data[c].first = b;
        data[b].second = a;
        data[c].second = a;
    }


}
