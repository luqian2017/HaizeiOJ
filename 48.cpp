/*************************************************************************
	> File Name: 48.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月22日 星期三 20时52分18秒
 ************************************************************************/

#include<iostream>
using namespace std;

int dp[10005];
int n, v;
int main() {
    cin >> n >> v;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        for(int j = a; j <= v; j++) {
            dp[j] = max(dp[j], dp[j - a] + b);
        }
    }
    cout << dp[v] << endl;
}
