//#include <iostream>
//#include <array>
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//
//    int tt;
//    std::cin >> tt;
//
//    int max, prev;
//    int res = 0;
//    for (int t = 0; t < tt; ++t) {
//        max = 0;
//        for (int x = 0; x < 4; ++x) {
//            std::cin >> prev;
//            if (prev > max)
//                max = prev;
//        }
//        res += max;
//    }
//
//    std::cout << res;
//
//    return 0;
//}

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

int tt;
int lim;
int layer = 0; // for DFS
std::array<int, 4> counter;
std::vector<std::array<int, 4>> data;

int prev, max;

void dfs() {
    ++layer;
    if (layer == tt) {
        for (int t = 0; t < 4; ++t)
            if (counter[t] < lim) {
                prev += data[layer][t];
                if (prev > max)
                    max = prev;
                prev -= data[layer][t];
            }
        --layer;
        return;
    }

    for (int t = 0; t < 4; ++t)
        if (counter[t] < lim) {
            ++counter[t];
            prev += data[layer][t];
            dfs();
            --counter[t];
            prev -= data[layer][t];
        }
    --layer;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> tt;
    data = decltype(data)(tt + 2);
    lim = tt / 4;
    for (int t = 1; t <= tt; ++t)
        std::cin >> data[t][0] >> data[t][1] >> data[t][2] >> data[t][3];

    dfs();

    std::cout << max;

    return 0;
}
