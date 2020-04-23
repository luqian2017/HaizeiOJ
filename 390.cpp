/*************************************************************************
	> File Name: 390.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月08日 星期三 20时34分33秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int n, m, mmax;
int num[100005];

int func(int len) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += num[i] / len;
    }
    return cnt;
}

int main() {
    //二分答案
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        mmax = max(mmax, num[i]);
    }
    int l = 0, r = mmax;
    while(l != r) {
        int mid = (l + r + 1)>>1;
        int s = func(mid);
        if(s >= m) l = mid;
        if(s < m) r = mid - 1;
    }
    cout << r << endl;
    return 0;
}
