/*************************************************************************
	> File Name: 391.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月22日 星期三 18时04分39秒
 ************************************************************************/

#include<iostream>
using namespace std;

long long n, m, num[100005], mmax, mmin;
long long check(long long mid) {
    //求出最大值为mid时的段数
    long long now = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        if(now + num[i] == mid) {
            cnt++;
            now = 0;
        } else if(now + num[i] > mid) {
            cnt++;
            now = num[i];
        } else {
            now += num[i];
        }  
    }
    if (now > 0) cnt++;
    return cnt;
}
long long func() {
    //二分答案 0000011111(最大值最小的那一个，就是第一个1)
    long long l = mmin, r = mmax;
    while(l != r) {
        long long mid = (l + r) >> 1;
        long long cnt = check(mid);//和为mid时分的段数
        if(cnt > m) {
            l = mid + 1;
        } else {
            r = mid;
        }

    }
    return l;
}


int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        mmax += num[i];//找出上届
        mmin = max(mmin, num[i]);//找出下限
    }
    cout << func() << endl;


    return 0;
}
