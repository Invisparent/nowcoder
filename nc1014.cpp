#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string istmp;
    getline(cin, istmp);
    istringstream iss(istmp);
    int N, M;
    iss >> N >> M;
    iss.clear();
    getline(cin, istmp);
    iss.str(istmp);
    vector<int> ivct;
    int itmp;
    while (iss >> itmp)
        ivct.push_back(itmp);
    vector<long long> xvct;
    long long r = 0;
    for (int t = 0; t != ivct.size(); t++) {
        r += ivct[t];
        if (t % 100 == 99) {
            xvct.push_back(r);
            r = 0;
        }
    }
    int x, y, xx, yy;
    while (cin >> x >> y) {
        long long r = 0;
        x--;
        y--;
        if (!xvct.empty() && y - x > 200) {
            xx = 1 + (x - x % 100) / 100;
            yy = (y - y % 100) / 100;
            for (; xx != yy; xx++)
                r += xvct[xx];
            do{
                r+=ivct[x];
                x++;
            }while (x%100!=0);
            for (; y % 100 != 0; y--)
                r += ivct[y];
            r += ivct[y];
        } else
            for (; x <= y; x++)
                r += ivct[x];
        cout << r << '\n';
        r = 0;
    }
    return 0;
}
