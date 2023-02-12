// https://ac.nowcoder.com/acm/contest/23156/1002
// 走出迷宫

// Multiple Solutions
// BFS with Queue

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

/**
 * String Defs:
 * 'x': Void
 * '.': Air
 * '#': Block
 * 'S': Start
 * 'E': End
 */
std::vector<std::string> data;

std::vector<std::vector<bool>> isVisited;

std::queue<std::pair<int, int>> posQueue;

inline bool bfs() {
    while (!posQueue.empty()) {
        auto pos = posQueue.front();
        posQueue.pop();
        if (data[pos.first][pos.second] == 'E')
            return true;
        isVisited[pos.first][pos.second] = true;

        if (!isVisited[pos.first + 1][pos.second] && data[pos.first + 1][pos.second] != '#')
            posQueue.emplace(pos.first + 1, pos.second);
        if (!isVisited[pos.first - 1][pos.second] && data[pos.first - 1][pos.second] != '#')
            posQueue.emplace(pos.first - 1, pos.second);
        if (!isVisited[pos.first][pos.second + 1] && data[pos.first][pos.second + 1] != '#')
            posQueue.emplace(pos.first, pos.second + 1);
        if (!isVisited[pos.first][pos.second - 1] && data[pos.first][pos.second - 1] != '#')
            posQueue.emplace(pos.first, pos.second - 1);
    }
    return false;
}

inline bool solve() {
    int n, m;
    if (!(std::cin >> n >> m))
        return false;

    isVisited = std::vector<std::vector<bool>>(n + 2, std::vector<bool>(m + 2, false));
    for (int t = 0; t <= n; ++t) {
        isVisited[t][0] = true;
        isVisited[t][m + 1] = true;
    }
    for (int t = 0; t <= m; ++t) {
        isVisited[0][t] = true;
        isVisited[n + 1][t] = true;
    }

    data = std::vector<std::string>(n + 2);
    data[0] = std::string(m + 2, 'x');
    data[n + 1] = std::string(m + 2, 'x');
    std::string strTmp;
    for (int t = 1; t <= n; ++t) {
        std::cin >> strTmp;
        data[t] = "x" + strTmp + "x";
    }

    int begI, begJ;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (data[i][j] == 'S') {
                begI = i;
                begJ = j;
                break;
            }

    while (!posQueue.empty())
        posQueue.pop();
    posQueue.emplace(begI, begJ);
    if (bfs())
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    while (solve());
    return 0;
}
