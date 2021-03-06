/*************************************************************************
	> File Name: 386.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月08日 星期三 19时40分42秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

struct node {
    int num, val;
};

node wm[100005];

bool cmp(node a, node b) {
    return a.val < b.val;
}

int main() {
   int n, m; 
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> wm[i].val;
        wm[i].num = i + 1;
    }
    sort(wm, wm + n, cmp);
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        int l = 0, r = n - 1;
        if(t > wm[n-1].val) {
            cout << 0 << endl;
            continue;
        }
        while(l != r) {//二分查找
            int  mid = (l + r)>>1;
            if(wm[mid].val < t) l = mid + 1;
            if(wm[mid].val >= t) r = mid;
        }
        cout << wm[l].num << endl;
    }

    return 0;
}
