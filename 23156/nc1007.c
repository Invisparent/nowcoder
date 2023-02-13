// https://ac.nowcoder.com/acm/contest/23156/1007
// 迷宫

// DNF
// See nc1007.cpp

#include <stdio.h>

#define maxn 505

typedef struct pos_t {
    int x;
    int y;
} pos_t;

typedef struct posWithVal_t {
    pos_t pos;
    int val;
} posWithVal_t;

int x, y;
char data[maxn][maxn];

posWithVal_t bfsQueue[maxn * maxn];

posWithVal_t *beg, *end;

void queueReset() {
    beg = &bfsQueue[0];
    end = &bfsQueue[0];
}

posWithVal_t queueTop() {
    return *beg;
}

void queuePop() {
    ++beg;
}

void queuePush(pos_t *inPos, int inVal) {
    end->pos = *inPos;
    end->val = inVal;
    ++end;
}

int xread() {
    int retVal = 0;
    char ch = (char) getchar();
    while (ch < '0' || ch > '9')
        ch = (char) getchar();
    while (ch >= '0' && ch <= '9') {
        retVal = (retVal << 3) + (retVal << 1) + ch - '0';
        ch = (char) getchar();
    }
    return retVal;
}

int main() {
    x = xread();
    y = xread();

    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= y; ++j)
            data[i][j] = (char) getchar();
        getchar();
    }
}
