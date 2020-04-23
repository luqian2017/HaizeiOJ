/*************************************************************************
	> File Name: 392.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月22日 星期三 18时47分32秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int n, m, num[100005], mmax;

int check(int mid) {
    int cnt = 1, now = 0;
    for(int i =0; i < n; i++) {
        if (num[i] - num[now] >= mid) {
            cnt++;
            now = i;
        }
    }
    return cnt;
}

int func() {
    int l = 1, r = mmax;
    while(l != r) {
        int mid = (l + r + 1) >> 1;// 防止死循环
        int cnt = check(mid);
        if (cnt >= m) {
            l = mid;// cnt == m 时需要考虑
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    //11111100000 二分答案的形式，具体要具体分析
    cin >> n >> m;
    for (int i= 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    mmax = num[n - 1] - num[0];
    cout << func() << endl;
    return 0;
}
