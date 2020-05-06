/*************************************************************************
	> File Name: 561.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月29日 星期三 19时12分34秒
 ************************************************************************/

#include<iostream>
#include <cstring>
using namespace std;
#define MAX_N 50000
int e, f, n;
int p[500 + 5], w[500 + 5], ans[MAX_N + 5];
int main() {
    memset(ans, 0x4f, sizeof(ans));//按照字节赋值
    ans[0] = 0;
    cin >> e >> f;
    f -= e;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = w[i]; j <= f; j++) {
            ans[j] = min(ans[j], ans[j - w[i]] + p[i]);
        }
    }
    if (ans[f] == 0x4F4F4F4F) {//int 为4个字节
        cout << "This is impossible." << endl;
    } else {
        cout << "The minimum amount of money in the piggy-bank is "<< ans[f]<<"." << endl;
    }
    return 0;
}
