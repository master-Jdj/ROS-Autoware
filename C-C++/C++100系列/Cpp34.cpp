// 题目：问555555的约数中，最大的三位数是多少？

#include <iostream>

using namespace std;

int main() {
    int maxn = 100;
    for (int i = 100; i<=999; i++ ) {
        if (555555 % i == 0) maxn = i;
    }

    cout << maxn << endl;
    return 0;
}