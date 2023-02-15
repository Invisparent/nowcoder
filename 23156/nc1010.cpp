// https://ac.nowcoder.com/acm/contest/23156/1010
// 数独挑战

// DNF
// Not Submitted

//#include <iostream>
//#include <unordered_set>
//#include <array>
//#include <cstdint>
//#include <utility>
//
//#define IVS_N 11
//#define IVS_C ((int)9*9)
//
//int filled = 0;
//
//// Align to 1
//std::array<std::array<uint8_t, IVS_N>, IVS_N> data;
//std::array<std::unordered_set<uint8_t>, IVS_N> iNum, jNum;
//
///**
// * For bNum:
// * 1 2 3
// * 4 5 6
// * 7 8 9
// */
//decltype(iNum) bNum;
//
//std::array<std::array<bool, IVS_N>, IVS_N> isVisited{};
//
//inline bool sudokuPosCheck(const std::pair<uint8_t, uint8_t> &pos) {
//    if (isVisited[pos.first][pos.second])
//        return false;
//    return true;
//}
//
//inline bool sudokuLegalCheck(const std::pair<uint8_t, uint8_t> &pos, uint8_t num) {
//    if (iNum[pos.first].find(num) != iNum[pos.first].end())
//        return false;
//    if (jNum[pos.second].find(num) != jNum[pos.second].end())
//        return false;
//    uint8_t bSeq = (pos.first + 2)
//}
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//
//    for (int i = 1; i <= 9; ++i)
//        for (int j = 1; j <= 9; ++j)
//            std::cin >> data[i][j];
//    for (int i = 1; i <= 9; ++i)
//        for (int j = 1; j <= 9; ++j)
//            if (data[i][j] != 0)
//                ++filled;
//
//}

// DNF * 2
// Not Submitted
// ...
// 思路出了大问题

//#include <cstdio>
//#include <vector>
//#include <unordered_set>
//#include <utility>
//
//int count = 0;
//char data[9][9];
//bool visited[9][9];
//std::vector<std::unordered_set<char>> iNum, jNum, bNum;
//
//inline int ivs2b(int i, int j) {
//    return (i / 3) * 3 + j / 3;
//}
//
//inline bool ivsBoundaryCheck(int i, int j) {
//    if (i < 0 || j < 0 || i >= 9 || j >= 9)
//        return false;
//    if (visited[i][j])
//        return false;
//    return true;
//}
//
//inline bool ivsCheck(int i, int j, char val) {
//    if (!ivsBoundaryCheck(i, j))
//        return false;
//
//    if (iNum[i].find(val) != iNum[i].end())
//        return false;
//    if (jNum[j].find(val) != jNum[j].end())
//        return false;
//    if (bNum[ivs2b(i, j)].find(val) != bNum[ivs2b(i, j)].end())
//        return false;
//
//    return true;
//}
//
//inline void ivsInsert(int i, int j, char val) {
//    data[i][j] = val;
//    visited[i][j] = true;
//    iNum[i].insert(val);
//    jNum[j].insert(val);
//    bNum[ivs2b(i, j)].insert(val);
//}
//
//inline void ivsRemove(int i, int j, char val) {
//    data[i][j] = '0';
//    visited[i][j] = false;
//    iNum[i].erase(val);
//    jNum[j].erase(val);
//    bNum[ivs2b(i, j)].erase(val);
//}
//
//inline auto ivsGetPos()
//-> std::pair<int, int> {
//    for (int i = 0; i < 9; ++i)
//        for (int j = 0; j < 9; ++j)
//            if (!visited[i][j])
//                return {i, j};
//    return {-1, -1};
//}
//
//bool dfs(int i, int j) {
//    for (char ch = '1'; ch <= '9'; ++ch) {
//        if (ivsCheck(i, j, ch)) {
//            ivsInsert(i, j, ch);
//            ++count;
//            if (count == 81)
//                return true;
//        }
//        if (ivsBoundaryCheck(i + 1, j))
//            if (dfs(i + 1, j))
//                return true;
//        if (ivsBoundaryCheck(i, j + 1))
//            if (dfs(i, j + 1))
//                return true;
//        if (ivsBoundaryCheck(i - 1, j))
//            if (dfs(i - 1, j))
//                return true;
//        if (ivsBoundaryCheck(i, j - 1))
//            if (dfs(i, j - 1))
//                return true;
//        --count;
//    }
//    return false;
//}
//
//int main() {
//    for (int i = 0; i < 9; ++i)
//        for (int j = 0; j < 9; ++j) {
//            data[i][j] = (char) std::getchar();
//            if (data[i][j] != '0') {
//                ivsInsert(i, j, data[i][j]);
//                ++count;
//            }
//            std::getchar();
//        }
//}

#include <cstdio>
#include <vector>
#include <unordered_set>
#include <utility>

char data[9][9];
bool visited[9][9];
std::vector<std::unordered_set<char>> iNum(9), jNum(9), bNum(9);
std::vector<std::pair<int, int>> dfsPath;
int dfsPathLen;

inline int ivs2b(const std::pair<int, int> &pos) {
    return (pos.first / 3) * 3 + pos.second / 3;
}

inline bool ivsBoundaryCheck(const std::pair<int, int> &pos) {
    return !visited[pos.first][pos.second];
}

inline bool ivsCheck(const std::pair<int, int> &pos, char val) {
    if (!ivsBoundaryCheck(pos))
        return false;

    if (iNum[pos.first].find(val) != iNum[pos.first].end())
        return false;
    if (jNum[pos.second].find(val) != jNum[pos.second].end())
        return false;
    if (bNum[ivs2b(pos)].find(val) != bNum[ivs2b(pos)].end())
        return false;

    return true;
}

inline void ivsRegister(const std::pair<int, int> &pos, char val) {
    visited[pos.first][pos.second] = true;
    data[pos.first][pos.second] = val;

    iNum[pos.first].insert(val);
    jNum[pos.second].insert(val);
    bNum[ivs2b(pos)].insert(val);
}

inline void ivsRemove(const std::pair<int, int> &pos, char val) {
    visited[pos.first][pos.second] = false;
    data[pos.first][pos.second] = '0';

    iNum[pos.first].erase(val);
    jNum[pos.second].erase(val);
    bNum[ivs2b(pos)].erase(val);
}

bool dfs(int step) {
    if (step == dfsPathLen)
        return true;
    auto pos = dfsPath[step];

    for (char ch = '1'; ch <= '9'; ++ch)
        if (ivsCheck(pos, ch)) {
            ivsRegister(pos, ch);
            if (dfs(step + 1))
                return true;
            ivsRemove(pos, ch);
        }
    return false;
}

int main() {
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j) {
            data[i][j] = (char) std::getchar();
            if (data[i][j] == '0')
                dfsPath.emplace_back(i, j);
            else {
                ivsRegister({i, j}, data[i][j]);
                visited[i][j] = true;
            }
            std::getchar();
        }
    dfsPathLen = (int) dfsPath.size();
    dfs(0);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            std::putchar(data[i][j]);
            if (j != 8)
                std::putchar(' ');
        }
        if (i != 8)
            std::putchar('\n');
    }
    return 0;
}
