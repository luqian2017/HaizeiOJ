/*************************************************************************
	> File Name: 43.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月29日 星期三 20时13分24秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n, num[1005][1005], ans[1005][1005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j =1 ; j <= i; j++) {
            cin >> num[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        //从上往下算， 也可以从下往上算
        for (int j = 1; j <= i; j++) {
            ans[i][j] = max(ans[i - 1][j - 1], ans[i - 1][j]) + num[i][j];
        }
    }
    int t = 0;
    for (int i = 1; i <= n; i++) {
        t = max(t, ans[n][i]);
    }
    cout << t << endl;
    return 0;
}
