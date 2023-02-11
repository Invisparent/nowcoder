// https://ac.nowcoder.com/acm/contest/23156/1001
// 老子的全排列呢

// Multiple Solutions
// raw

#include <stdio.h>

#define IVS_STRLEN 8

void printStr(char *str) {
    for (int t = 0; t < IVS_STRLEN; ++t) {
        putchar(str[t]);
        if (t != IVS_STRLEN - 1)
            putchar(' ');
    }
    putchar('\n');
}

void charSwap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * naiveSort
 * I'm lazy. I don't want to use quickSort
 * Haha~
 */
void sortStr(char *beg, const char *end) {
    while (beg < end) {
        char *ptr = beg;
        while (ptr <= end) {
            if (*beg > *ptr)
                charSwap(beg, ptr);
            ++ptr;
        }
        ++beg;
    }
}

void nextPermutation(char *str) {
    char *traverseIterA = str + IVS_STRLEN - 1 - 1;
    while (*traverseIterA > *(traverseIterA + 1))
        --traverseIterA;
    char *traverseIterB = str + IVS_STRLEN - 1;
    while (*traverseIterB < *traverseIterA)
        --traverseIterB;
    charSwap(traverseIterA, traverseIterB);
    sortStr(traverseIterA + 1, str + IVS_STRLEN - 1);
}

int main() {
    // !!!
    // WHAT THE FUCK ???
    //char str[8] = "12345678";
    char str[9] = "12345678";
    printStr(str);
    for (int t = 1; t < 40320; ++t) {
        nextPermutation(str);
        printStr(str);
    }
    return 0;
}
