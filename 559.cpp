/*************************************************************************
	> File Name: 559.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月29日 星期三 18时28分16秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Node {
    double s, f;
    double aver; 
};
int n, m;
bool comp(Node a, Node b) {
    return a.aver > b.aver;
}

int main() {
    cin >> m >> n;
    Node *node = (Node *)malloc(sizeof(Node) * n);
    for (int i = 0; i < n; i++) {
        cin >> node[i].s >> node[i].f;
        node[i].aver = node[i].s / node[i].f;
    }
    sort(node,node + n, comp);
    double ans = 0;
    int j = 0;
    while(m) {
        if (node[j].f >= m) {
            ans += (node[j].aver * m);
            m = 0;
        } else {
            ans += node[j].s;
            m -= node[j].f;
        }
        j++;
    }
    printf("%.3lf\n",ans);
    return 0;
}
