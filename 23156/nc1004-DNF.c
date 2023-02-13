// https://ac.nowcoder.com/acm/contest/23156/1004
// Jelly

// DNF
// SIGSEGV

//#include <stdio.h>
//#include <stdint.h>
//
//#define maxn 105
//#define IVS_OFFSET_COUNT 6
//
//int xread();
//
//typedef struct pos_t pos_t;
//typedef struct posWithVal_t posWithVal_t;
//
//pos_t posPlus(pos_t *a, pos_t *b);
//
//uint8_t posComp(pos_t *a, pos_t *b);
//
//void queuePush(pos_t *posData, int stepData);
//
//void queuePop();
//
//posWithVal_t queueTop();
//
//uint8_t queueIsEmpty();
//
//uint8_t queryIsVisited(pos_t *pos);
//
//void setVisited(pos_t *pos);
//
//uint8_t isLegalPos(pos_t *pos);
//
//int bfs();
//
//int xread() {
//    int retVal = 0;
//    char ch = (char) getchar();
//    while (ch < '0' || ch > '9')
//        ch = (char) getchar();
//    while (ch >= '0' && ch < '9') {
//        retVal = (retVal << 3) + (retVal << 1) + ch - '0';
//        ch = (char) getchar();
//    }
//    return retVal;
//}
//
//struct pos_t {
//    int x;
//    int y;
//    int z;
//};
//
//struct posWithVal_t {
//    pos_t pos;
//    int val;
//};
//
//pos_t posPlus(pos_t *a, pos_t *b) {
//    pos_t retVal;
//    retVal.x = a->x + b->x;
//    retVal.y = a->y + b->y;
//    retVal.z = a->z + b->z;
//    return retVal;
//}
//
//uint8_t posComp(pos_t *a, pos_t *b) {
//    return a->x == b->x && a->y == b->y && a->z == b->z;
//}
//
//char jellyData[maxn][maxn][maxn];
//uint8_t isVisited[maxn][maxn][maxn];
///**
// * Maybe... There?
// */
////pos_t offsetPosData[IVS_OFFSET_COUNT] = {{1,  0,  0},
////                                         {-1, 0,  0},
////                                         {0,  1,  0},
////                                         {0,  -1, 0},
////                                         {0,  0,  1},
////                                         {0,  0,  -1}};
//pos_t offsetPosData[IVS_OFFSET_COUNT] = {{1,  0,  0},
//                                         {0,  1,  0},
//                                         {-1, 0,  0},
//                                         {0,  -1, 0},
//                                         {0,  0,  1},
//                                         {0,  0,  -1}};
//pos_t targetPos;
//posWithVal_t bfsQueue[maxn][maxn][maxn];
//posWithVal_t *queueBeg = &bfsQueue[0][0][0], *queueEnd = &bfsQueue[0][0][0];
//
//void queuePush(pos_t *posData, int stepData) {
//    queueEnd->pos = *posData;
//    queueEnd->val = stepData;
//    ++queueEnd;
//}
//
//void queuePop() {
//    ++queueBeg;
//}
//
//posWithVal_t queueTop() {
//    return *queueBeg;
//}
//
//uint8_t queueIsEmpty() {
//    return queueBeg == queueEnd;
//}
//
//uint8_t queryIsVisited(pos_t *pos) {
//    return isVisited[pos->x][pos->y][pos->z];
//}
//
//void setVisited(pos_t *pos) {
//    isVisited[pos->x][pos->y][pos->z] = 1;
//}
//
//uint8_t isLegalPos(pos_t *pos) {
//    return jellyData[pos->x][pos->y][pos->z] == '.';
//}
//
//int bfs() {
//    while (!queueIsEmpty()) {
//        posWithVal_t presentPosWithStep = queueTop();
//        if (posComp(&presentPosWithStep.pos, &targetPos))
//            return presentPosWithStep.val;
//        queuePop();
//        isVisited[presentPosWithStep.pos.x][presentPosWithStep.pos.y][presentPosWithStep.pos.z] = 1;
//
//        for (int t = 0; t < IVS_OFFSET_COUNT; ++t) {
//            pos_t nextPos = posPlus(&presentPosWithStep.pos, &offsetPosData[t]);
//            if (!queryIsVisited(&nextPos) && isLegalPos(&nextPos))
//                queuePush(&nextPos, presentPosWithStep.val + 1);
//        }
//    }
//    return -1;
//}
//
//int main() {
//    int n = xread();
//
//    isVisited[1][1][1] = 1;
//    targetPos.x = targetPos.y = targetPos.z = n;
//
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= n; ++j) {
//            for (int k = 1; k <= n; ++k)
//                jellyData[i][j][k] = (char) getchar();
//            getchar();
//        }
//    }
//
//    for (int i = 0; i < n + 2; ++i)
//        for (int j = 0; j < n + 2; ++j) {
//            jellyData[0][i][j] = '*';
//            jellyData[n + 1][i][j] = '*';
//            jellyData[i][0][j] = '*';
//            jellyData[i][n + 1][j] = '*';
//            jellyData[i][j][0] = '*';
//            jellyData[i][j][n + 1] = '*';
//        }
//
//    pos_t beginPos = {1, 1, 1};
//    queuePush(&beginPos, 1);
//    printf("%d", bfs());
//    return 0;
//}
