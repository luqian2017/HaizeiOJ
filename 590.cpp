/*************************************************************************
	> File Name: 590.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月05日 星期二 17时08分19秒
 ************************************************************************/

#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, num[1005][1005], down[1005][1005], up[1005][1005], mmax[1005], mmax_ind[1005], mmax2[1005];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {//存储从上到下的路径最大和
        for (int j = 1; j <= i; j++) {
            down[i][j] = max(down[i - 1][j - 1], down[i - 1][j]) + num[i][j];
        }
    }
    for (int i = n; i > 0; i--) {//存储从下到上的路径最大和
        for (int j = 1; j <= i; j++) {
            up[i][j] = max(up[i + 1][j + 1], up[i + 1][j]) + num[i][j];
        }
    }
    for (int i = 2; i <= n; i++) {
        int ind1 = 0, ind1_max = 0, ind2_max = 0;
        for (int j = 1; j <= i; j++) {
            int t = down[i][j] + up[i][j] - num[i][j];
            int temp = 0;
            if (t > ind1_max) {//找出过该点的最大值
                ind1_max = t;
                ind1 = j;
                temp = 1;
             }
        }
                //找出次大值
        for (int j = 1; j <= i; j++) {
            int t = down[i][j] + up[i][j] - num[i][j];
            if (t > ind2_max && j != ind1) {
                ind2_max = t;
            }
        }
        mmax[i] = ind1_max;//数组存储最大值，次大值以及下标（每行的）
        mmax_ind[i] = ind1;
        mmax2[i] = ind2_max;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == 1 && b == 1) {//顶点的时候，不存在路径
            printf("-1\n");
            continue;
        }
        if (mmax_ind[a] == b) {
            printf("%d\n", mmax2[a]);
        } else {
            printf("%d\n", mmax[a]);
        }
    }
    return 0;
}
