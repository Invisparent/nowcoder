// https://ac.nowcoder.com/acm/contest/23156/1014
// wyh的迷宫

// Multiple Solutions
// BFS

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define IVS_N 505

typedef struct pos_t {
    int x;
    int y;
} pos_t;

pos_t begPos, endPos;

uint8_t visited[IVS_N][IVS_N];
pos_t bfsQueue[IVS_N * IVS_N];

// For bfsQueue
pos_t *beg, *end;

int xread() {
    // ?????????????????????????????????????????
    // ?????
    // 不初始化，喜提SIGSEGV，RE一发
    // 呵呵呵

    //int retVal;
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

void ivsInsert(const pos_t *data) {
    *end = *data;
    ++end;
}

pos_t ivsTop() {
    return *beg;
}

void ivsPop() {
    ++beg;
}

uint8_t ivsEmpty() {
    return beg == end;
}

void ivsInit() {
    memset(visited, 0, sizeof(visited));
    beg = &bfsQueue[0];
    end = beg;
}

uint8_t bfs() {
    while (!ivsEmpty()) {
        pos_t prevPos = ivsTop();
        if (prevPos.x == endPos.x && prevPos.y == endPos.y)
            return 1;

        ivsPop();

        pos_t nextPos = prevPos;
        ++nextPos.x;
        if (!visited[nextPos.x][nextPos.y]) {
            visited[nextPos.x][nextPos.y] = 1;
            ivsInsert(&nextPos);
        }

        --nextPos.x;
        ++nextPos.y;
        if (!visited[nextPos.x][nextPos.y]) {
            visited[nextPos.x][nextPos.y] = 1;
            ivsInsert(&nextPos);
        }

        --nextPos.x;
        --nextPos.y;
        if (!visited[nextPos.x][nextPos.y]) {
            visited[nextPos.x][nextPos.y] = 1;
            ivsInsert(&nextPos);
        }

        ++nextPos.x;
        --nextPos.y;
        if (!visited[nextPos.x][nextPos.y]) {
            visited[nextPos.x][nextPos.y] = 1;
            ivsInsert(&nextPos);
        }
    }

    return 0;
}

void solve() {
    int n = xread();
    int m = xread();
    ivsInit();

    // Add boundary
    for (int t = 0; t <= n + 1; ++t) {
        visited[t][0] = 1;
        visited[t][m + 1] = 1;
    }
    for (int t = 0; t <= m + 1; ++t) {
        visited[0][t] = 1;
        visited[n + 1][t] = 1;
    }

    char ch;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ch = (char) getchar();
            if (ch == 's') {
                begPos.x = i;
                begPos.y = j;
            } else if (ch == 't') {
                endPos.x = i;
                endPos.y = j;
            } else if (ch == 'x')
                visited[i][j] = 1;
        }
        getchar();
    }

    ivsInsert(&begPos);
    visited[begPos.x][begPos.y] = 1;

    if (bfs())
        printf("YES\n");
    else
        printf("NO\n");
}

int main() {
    int tt = xread();

    while (tt--)
        solve();

    return 0;
}
