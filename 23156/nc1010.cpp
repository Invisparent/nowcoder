// https://ac.nowcoder.com/acm/contest/23156/1010
// 数独挑战

// DNF
// See nc1010.c

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
