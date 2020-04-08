/*************************************************************************
	> File Name: 405.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月21日 星期六 13时47分48秒
 ************************************************************************/
#include<queue>
#include<iostream>
using namespace std;

int n, m, k, ans;
char mmap[3005][3005];
int check[3005][3005];//去重， 保留答案
int dir[4][2] = {0, 1, 1, 0, 0 ,-1, -1, 0};
struct node {
    int x, y;
};
queue<node> que;
void func(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if(check[tx][ty] == 0 && mmap[tx][ty] != mmap[x][y] && mmap[tx][ty]) {
            ans++;
            check[tx][ty] = 1;
            que.push({tx,ty});
            func(tx, ty);
        }
    }
}


int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        cin>> (&mmap[i][1]);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(check[i][j] == 0) {
                //没有被搜国
                check[i][j] = 1;
                que.push({i, j});
                func(i, j);
                while(!que.empty()) {
                    node temp = que.front();
                    que.pop;
                    check[temp.x][temp.x] = ans;
                }
            }
        }
    }
    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        cout << check[a][b]<<endl;
    }
    return 0;
}
