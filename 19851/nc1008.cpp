#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> vvi(N, std::vector<int>(N));
    // vvi[y][x]
    vvi[0][N / 2] = 1;
    int x = N / 2, y = 0;
    for (int k = 2; k <= N * N; ++k) {
        if (y == 0 && x != N - 1) {
            ++x;
            y = N - 1;
        } else if (x == N - 1 && y != 0) {
            x = 0;
            --y;
        } else if (y == 0 && x == N - 1)
            ++y;
        else {
            if (vvi[y - 1][x + 1] == 0) {
                --y;
                ++x;
            } else
                ++y;
        }
        vvi[y][x] = k;
    }
    for (const std::vector<int> &vi: vvi) {
        for (const int &i: vi)
            std::cout << i << ' ';
        std::cout << std::endl;
    }
    return 0;
}
