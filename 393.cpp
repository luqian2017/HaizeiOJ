/*************************************************************************
	> File Name: 393.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月22日 星期三 19时17分29秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
double mmax;
double num[10005];

int check(double mid) {
    int cnt = 0;
    for(int i = 0; i < n; i++) 
        cnt += (num[i] / mid);
    return cnt;
}

double func() {
    double l = 0, r = mmax;
    while(r - l > 0.00001) {
        double mid = (l + r)/2;
        int x = check(mid);
        if (x >= k) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
   cin >> n >> k; 
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        mmax = max(mmax, num[i]);
    } 
    double ans = func();
    printf("%.2lf\n",ans);
    return 0;
}
