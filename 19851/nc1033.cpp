#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

// 智障玩意输出还需要升序排列一下， 不然不给过

int main() {
    int M, N, K, L, D;
    std::cin >> M >> N >> K >> L >> D;
    int xA, yA, xB, yB;
    std::vector<std::pair<int, int>> vx(N - 1), vy(M - 1);
    for (int t = 1; t <= M - 1; ++t)
        vy[t - 1].second = t;
    for (int t = 1; t <= N - 1; ++t)
        vx[t - 1].second = t;
    while (std::cin >> yA >> xA >> yB >> xB) {
        if (xA == xB)
            ++vy[(yA + yB) / 2 - 1].first;
        else
            ++vx[(xA + xB) / 2 - 1].first;
    }
    std::sort(vx.begin(), vx.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    });
    std::sort(vy.begin(), vy.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    });
    std::vector<int> vox(L), voy(K);
    for (int t = 0; t < K; ++t)
        voy[t] = vy[t].second;
    for (int t = 0; t < L; ++t)
        vox[t] = vx[t].second;
    std::sort(vox.begin(), vox.end());
    std::sort(voy.begin(), voy.end());
    for (const int &ini: voy)
        std::cout << ini << ' ';
    std::cout << std::endl;
    for (const int &ini: vox)
        std::cout << ini << ' ';
    return 0;
}
