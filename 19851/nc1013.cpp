#include <stdio.h>

#define modNum 1000000007

int main() {
    int n;
    scanf("%d", &n);
    long long arrll[n];
    arrll[0] = 0, arrll[1] = 1, arrll[2] = 2;
    for (int t = 3; t <= n; ++t)
        arrll[t] = (arrll[t - 1] + arrll[t - 2] * (t - 1) % modNum) % modNum;
    printf("%lld", arrll[n]);
    return 0;
}
