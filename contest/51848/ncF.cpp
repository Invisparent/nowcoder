#include <cstdio>
#include <set>

inline int xread() {
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
    std::set<int> si;
    for (int t = 1; t <= n; ++t)
        si.insert(t);
    int op, val;
    for (int t = 0; t < k; ++t) {
        op = xread();
        val = xread();
        if (op == 1)
            si.erase(val);
        else {
            auto iter = si.find(val);
            if (iter == si.begin())
                printf("0\n");
            else {
                --iter;
                printf("%d\n", *iter);
            }
        }
    }
    return 0;
}
