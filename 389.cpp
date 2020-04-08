/*************************************************************************
	> File Name: 389.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月08日 星期三 20时47分35秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int n, m, num[100005], mmax;

int func2(int len) {
    int cnt = 1, now = 0;//第一的座坐一个
    for(int i = 1; i < n; i++) {
        if(num[i] - num[now] >= len){
            cnt++;
            now = i;
        }
    }
    return cnt;//返回len长度可以放人的数量
}

int func() {
    int l = 0, r = mmax;
    while(l != r) {
        int mid = (l + r + 1)>>1;
        int cnt = func2(mid);//长度可以放人的数量是mid 的时候的人的数量
        if(cnt >= m) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        mmax = max(mmax, num[i]);
    }
    sort(num, num + n);
    int ans = func();
    cout << ans << endl;
    return 0;
}
