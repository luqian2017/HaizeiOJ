/*************************************************************************
	> File Name: 560.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月29日 星期三 21时06分50秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
int n, m;
int v[30], q[30], f[30005];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d",&v[i],&q[i]);
    }
    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + v[i] * q[i]);
        }
    }
    cout << f[n] << endl;
    return 0;
}

