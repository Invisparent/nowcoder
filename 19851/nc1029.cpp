#include <stdio.h>

int main() {
    int i;
    scanf("%d", &i);
    long long lltmp, r = 0;
    for (int t = 1; t <= i; ++t) {
        scanf("%lld", &lltmp);
        if (lltmp < 0)
            r += t * lltmp;
        else
            r += lltmp;
    }
    printf("%lld", r);
    return 0;
}
