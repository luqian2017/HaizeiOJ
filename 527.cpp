/*************************************************************************
	> File Name: 527.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月01日 星期三 20时08分17秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

int n, m, d, check[105][105][105];//第三层表示能量的剩余值
char mmap[105][105];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

struct node {
    int x, y, s, d;
};


int main() {
    cin >> n>>m>>d;
    for(int i = 1; i <= n ;i++) {
        cin >> &mmap[i][1];
    }
    queue<node>que;
    que.push({1, 1,0, d});
    for(int i = 0; i <= d; i++) {
        check[1][1][i] = 1;//防止循环飞行（不同能量下的（1，1）点都国)
    }
    while(!que.empty()) {
        node tmp = que.front();
        que.pop();
        for(int i = 0; i < 4; i++) {
            for(int j = 2; j <= tmp.d; j++) {//j=2开始，1步的情况可以直接走
                int x = tmp.x +j* dir[i][0];//飞行的情况
                int y = j*dir[i][1] + tmp.y;
                if(x == n && y==m) {
                    cout << tmp.s + 1 << endl;
                    return 0;
                }
            
            if(mmap[x][y] == 0) break;//出界
            if(mmap[x][y] == 'P' && check[x][y][tmp.d - j] == 0) {
                check[x][y][tmp.d - j] = 1;
                que.push({x, y, tmp.s+1, tmp.d - j});
            }
            }//移动的时候
            int x = tmp.x + dir[i][0];
            int y = tmp.y + dir[i][1];
            if(x == n && y == m) {
                cout << tmp.s+1<<endl;
                return 0;
            }
            if(mmap[x][y] == 'P' && check[x][y][tmp.d] == 0) {
                check[x][y][tmp.d] = 1;
                que.push({x, y, tmp.s+1, tmp.d});
            }
        }
    }
    cout << "impossible"<<endl;
    return 0;
}
