#include <iostream>
#include <vector>
#include <algorithm>

// 想不到吧，重复元素unique一下就是答案
// 其实思路很简单，每次遇到重复的元素，总是挑选该元素和数组中最大的元素相加，新产生的插入到序列中的元素的值必然大于之前序列中的最大值
// 所以一直这么操作，不会新增重复的元素，后面的你懂的

int main() {
    int n;
    std::cin >> n;
    std::vector<int> vi(n);
    for (int t = 0; t < n; ++t)
        std::cin >> vi[t];
    std::sort(vi.begin(), vi.end());
    std::cout << vi.end() - std::unique(vi.begin(), vi.end());
    return 0;
}
