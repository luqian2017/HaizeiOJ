/*************************************************************************
	> File Name: 403.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月01日 星期三 18时11分37秒
 ************************************************************************/

#include<iostream>
#include<queue>

struct node {
    int x, y;
    int step;
};
int n, m, x, y;
int mmap[405][405];
int dir[8][2] = {
    1, 2, 1, -2, 2, 1, 2, -1,
    -1, 2, -1, -2, -2, 1, -2, -1
};
using namespace std;
queue<node>que;
int main() {
    cin >> n >> m >> x >> y;
    que.push({x,y,0});
    mmap[x][y] = -2;//起始点
    while(!que.empty()) {
            node temp = que.front();
            que.pop();
            for(int i = 0; i < 8; i++) {
                int x = temp.x + dir[i][0];
                int y = temp.y + dir[i][1];
                if(x < 1 || y < 1 || x > n|| y > m) continue;
            
            if(mmap[x][y] == 0) {
                mmap[x][y] = temp.step + 1;
                que.push({x, y, temp.step + 1});
            }

        }}
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m ;j++) {
            if(j != 1) cout << " ";
            if(mmap[i][j] == -2) {
                cout << 0;
            } else if(mmap[i][j]){
                cout << mmap[i][j];
            } else {
                cout << -1;
            }
        }
        cout << endl;
    }


    return 0;
}

