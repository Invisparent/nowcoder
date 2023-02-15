// https://ac.nowcoder.com/acm/contest/23156/1010
// 数独挑战

// DNF
// See nc1010.cpp

//#include <stdio.h>
//#include <stdint.h>
//
//#define IVS_N 9
//#define IVS_C 3
//#define IVS_T ((int8_t) IVS_N * IVS_N)
//
//int8_t data[IVS_N][IVS_N];
//int8_t isVisited[IVS_N][IVS_N];
//int8_t visitedCount = 0;
//
///**
// * Too redundant
// * Refactor it
// */
////int8_t iNum[IVS_N][IVS_N], jNum[IVS_N][IVS_N], bNum[IVS_N][IVS_N];
////int8_t *iNumPtr[IVS_N][2], *jNumPtr[IVS_N][2], *bNumPtr[IVS_N][2];
////
////void ivsInit() {
////    for (int t = 0; t < IVS_N; ++t) {
////        iNumPtr[t][0] = iNumPtr[t][1] = &iNum[t][0];
////        jNumPtr[t][0] = jNumPtr[t][1] = &jNum[t][0];
////        bNumPtr[t][0] = bNumPtr[t][1] = &bNum[t][0];
////    }
////}
////
////void ivsInsert(int8_t typ, int8_t pos, int8_t val){
////
////}
//
///**
// * IVS_C Defs:
// * 0: iNum
// * 1: jNum
// * 2: bNum
// */
//int8_t numSet[IVS_C][IVS_N][IVS_N];
//
///**
// * Like iterator in Cpp
// */
//int8_t *numSetPtr[IVS_C][IVS_N][2];
//
//void ivsInit() {
//    for (int t = 0; t < IVS_N; ++t)
//        for (int c = 0; c < IVS_C; ++c)
//            numSetPtr[c][t][0] = numSetPtr[c][t][1] = &numSet[c][t][0];
//}
//
//void ivsInsert(int8_t typ, int8_t pos, int8_t val) {
//    *numSetPtr[typ][pos][1] = val;
//    ++numSetPtr[typ][pos][1];
//}
//
//void ivsPop(int8_t typ, int8_t pos) {
//    --numSetPtr[typ][pos][1];
//}
//
//int8_t ivsContains(int8_t typ, int8_t pos, int8_t val) {
//    int8_t *beg = numSetPtr[typ][pos][0], *end = numSetPtr[typ][pos][1];
//    while (beg != end) {
//        if (*beg == val)
//            return 1;
//        ++beg;
//    }
//    return 0;
//}
//
//int8_t ivsPos2b(int8_t i, int8_t j) {
//    return (int8_t) ((i / 3) * 3 + (j / 3));
//}
//
//int8_t ivsCheck(int8_t i, int8_t j, int8_t val) {
//    if (i < 0 || i >= IVS_N || j < 0 || j >= IVS_N)
//        return 0;
//
//    if (isVisited[i][j])
//        return 0;
//
//    if (ivsContains(0, i, val))
//        return 0;
//    if (ivsContains(1, j, val))
//        return 0;
//    if (ivsContains(2, ivsPos2b(i, j), val))
//        return 0;
//
//    return 1;
//}
//
//void ivsIn(int8_t i, int8_t j, int8_t val) {
//    ivsInsert(0, i, val);
//    ivsInsert(1, j, val);
//    ivsInsert(2, ivsPos2b(i, j), val);
//}
//
//void ivsOut(int8_t i, int8_t j) {
//    ivsPop(0, i);
//    ivsPop(1, j);
//    ivsPop(2, ivsPos2b(i, j));
//}
//
//void ivsReadData() {
//    for (int8_t i = 0; i < IVS_N; ++i)
//        for (int8_t j = 0; j < IVS_N; ++j) {
//            data[i][j] = (int8_t) (getchar() - '0');
//
//            if (data[i][j] != 0) {
//                ivsIn(i, j, data[i][j]);
//                isVisited[i][j] = 1;
//                ++visitedCount;
//            }
//
//            getchar();
//        }
//}
//
//int16_t getAvailablePos() {
//    int16_t retVal;
//    int8_t i = 0, j = 0;
//    for (; i < IVS_N; ++i)
//        for (; j < IVS_N; ++j)
//            if (!isVisited[i][j])
//                break;
//
//    *(int8_t *) &retVal = i;
//    *((int8_t *) &retVal + 1) = j;
//    return retVal;
//}
//
//void dfs(int8_t i, int8_t j, int8_t val) {
//
//}
//
//int main() {
//    ivsInit();
//    ivsReadData();
//
//}
