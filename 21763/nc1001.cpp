/**
* 链接：https://ac.nowcoder.com/acm/contest/21763/1001
来源：牛客网

题目描述
给你一个数，让他进行巴啦啦能量，沙鲁沙鲁，小魔仙大变身，如果进行变身的数不满足条件的话，就继续让他变身。。。直到满足条件为止。
巴啦啦能量，沙鲁沙鲁，小魔仙大变身：对于一个数，把他所有位上的数字进行加和，得到新的数。
如果这个数字是个位数的话，那么他就满足条件。
输入描述:
给一个整数数字n(1<=n<=1e9)。
输出描述:
输出由n经过操作满足条件的数
示例1
输入
复制
12
输出
复制
3
说明
12 -> 1 + 2 = 3
示例2
输入
复制
38
输出
复制
2
说明
38 -> 3 + 8 = 11 -> 1 + 1 = 2
*/

#include <iostream>
#include <string>

inline int calculate(int n) {
    if (n < 10)
        return n;
    std::string s = std::to_string(n);
    int r = 0;
    for (const char &ch: s)
        r += ch - '0';
    return calculate(r);
}

int main() {
    int n;
    std::cin >> n;
    std::cout << calculate(n);
    return 0;
}
