// https://ac.nowcoder.com/acm/contest/23156/1015
// 八数码

// DNF

//#include <stdio.h>
//#include <stdint.h>
//
//#define IVS_N 3
//
//char data[IVS_N][IVS_N];
//
//uint8_t isLegal() {
//    char ch[IVS_N * IVS_N - 1];
//    for (int t = 0; t < IVS_N * IVS_N - 1;) {
//        ch[t] = data[t / IVS_N][t % IVS_N];
//        if (ch[t] != 'x')
//            ++t;
//    }
//
//    int revCount = 0;
//    for (int i = 0; i < IVS_N * IVS_N - 1; ++i)
//        for (int j = i + 1; j < IVS_N * IVS_N - 1; ++j)
//            if (ch[i] > ch[j])
//                ++revCount;
//
//    return !(revCount % 2);
//}
//
//int main() {
//    for (int i = 0; i < IVS_N; ++i)
//        for (int j = 0; j < IVS_N; ++j) {
//            data[i][j] = (char) getchar();
//            if (!(i == IVS_N - 1 && j == IVS_N - 1))
//                getchar();
//        }
//
//    if (!isLegal()) {
//        printf("unsolvable\n");
//        return 0;
//    }
//}
