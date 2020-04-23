/*************************************************************************
	> File Name: 47.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月22日 星期三 20时04分20秒
 ************************************************************************/

#include<iostream>
using namespace std;
int all, n, ans[10005], w[105], v[105];
int main() {
    cin >> all >> n;
    for(int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 0; i < n; i++) {
        for(int j = all; j > 0; j--) {
            if ( j < w[i] ) {
                break;
            } else {
                //从后往前，防止前面改变影响后面
                ans[j] = max(ans[j], v[i] + ans[j - w[i]]);
            }
        }
    }
    cout << ans[all] << endl;
}

/*
int all, n, w[105], v[105], ans[105][10005];

int main() {
    cin >> all >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= all; j++) {
            if(j < w[i]) {
                //装不下
                ans[i][j] = ans[i - 1][j];
            } else {
                ans[i][j] = max(ans[i - 1][j], v[i] + ans[i - 1][j - w[i]]);
            }
        }
    }
    cout << ans[n][all] << endl;

    return 0;
}*/
