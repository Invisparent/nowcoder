#include <stdio.h>

#define IVS_N 5010



int xread() {
    int retVal = 0;
    char ch = (char) getchar();

    while (ch < '0' || ch > '9')
        ch = (char) getchar();

    while (ch >= '0' && ch <= '9') {
        retVal = (retVal << 1) + (retVal << 3) + ch - '0';
        ch = (char) getchar();
    }

    return retVal;
}

int main() {
    int n = xread();
    int k = xread();


}
