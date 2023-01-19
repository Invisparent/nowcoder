// https://ac.nowcoder.com/acm/contest/24213/1015
// 购物

// Multiple Solutions
// priorityQueue Manual

// DNF
// Fuck

//#include <stdio.h>
//#include <string.h>
//
//#define maxn 305
//
//int dat[maxn][maxn], pq[maxn * maxn];
//
//const int beginPos = 1;
//// One element after the last one
//int endPos = 1;
//
//int min(int a, int b);
//
//int max(int a, int b);
//
//void swap(int *a, int *b);
//
//void swim(int pos);
//
//void sink(int pos);
//
//void push(int i);
//
//int pop();
//
//void swap(int *a, int *b) {
//    int x = *a;
//    *a = *b;
//    *b = x;
//}
//
//int min(int a, int b) {
//    if (a < b)
//        return a;
//    return b;
//}
//
//int max(int a, int b) {
//    if (a > b)
//        return a;
//    return b;
//}
//
//void swim(int pos) {
//    if (pos == 1)
//        return;
//    if (pq[pos] < pq[pos / 2]) {
//        swap(&pq[pos], &pq[pos / 2]);
//        swim(pos / 2);
//    }
//}
//
//void sink(int pos) {
//    if (pq[pos * 2] >= pq[pos] && pq[pos * 2 + 1] >= pq[pos])
//        return;
//    if (pq[pos * 2] <= pq[pos * 2 * 1]) {
//        swap(&pq[pos], &pq[pos * 2]);
//        sink(pos * 2);
//    } else {
//        swap(&pq[pos], &pq[pos * 2 + 1]);
//        sink(pos * 2 + 1);
//    }
//}
//
//void push(int i) {
//    pq[endPos] = i;
//    ++endPos;
//    swim(i);
//}
//
//int pop() {
//    int x = pq[beginPos];
//    swap(&pq[beginPos], &pq[endPos - 1]);
//    sink(beginPos);
//    return x;
//}
//
//int main() {
//    memset(pq, 0x3f, sizeof(pq));
//    int n, m;
//    scanf("%d%d", &n, &m);
//    for (int i = 1; i <= n; ++i)
//        for (int j = 1; j <= m; ++j)
//            scanf("%d", &dat[i][j]);
//
//}
