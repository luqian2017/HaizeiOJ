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
int n, m;
char mmap[200][200];
int dir[8][2] = {
    1, 2, 1, -2, 2, 1, 2, -1,
    -1, 2, -1, -2, -2, 1, -2, -1
};
using namespace std;
queue<node>que;
int main() {
    cin >> m >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if(mmap[i][j] == 'K') {
                que.push({i,j,0});
            }

    }}
        while(!que.empty()) {
            node temp = que.front();
            que.pop();
            for(int i = 0; i < 8; i++) {
                int x = temp.x + dir[i][0];
                int y = temp.y + dir[i][1];
                if(x < 1 || y < 1 || x > n|| y > m) continue;
                if(mmap[x][y] == 'H') {
                    cout << temp.step + 1 << endl;
                    return 0;
                }
            
            if(mmap[x][y] == '.') {
                mmap[x][y] = 0;
                que.push({x, y, temp.step + 1});
            }

        }}



    return 0;
}

