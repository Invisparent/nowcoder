// https://ac.nowcoder.com/acm/contest/23156/1002
// 走出迷宫

// Multiple Solutions
// DFS

#include <iostream>
#include <vector>
#include <string>

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

bool dfs(int x, int y) {
    if (data[x][y] == 'E')
        return true;
    isVisited[x][y] = true;
    if (!isVisited[x + 1][y] && data[x + 1][y] != '#')
        if (dfs(x + 1, y))
            return true;
    if (!isVisited[x - 1][y] && data[x - 1][y] != '#')
        if (dfs(x - 1, y))
            return true;
    if (!isVisited[x][y + 1] && data[x][y + 1] != '#')
        if (dfs(x, y + 1))
            return true;
    if (!isVisited[x][y - 1] && data[x][y - 1] != '#')
        if (dfs(x, y - 1))
            return true;
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
    std::string strTmp;
    data[0] = std::string(m + 2, 'x');
    data[n + 1] = std::string(m + 2, 'x');
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

    if (dfs(begI, begJ))
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
