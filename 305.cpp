/*************************************************************************
	> File Name: 305.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月01日 星期三 19时06分06秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

struct node{
    int x, y, step;
};

char mmap[205][205];
int n, m, x, y;
int dir[8][2] = {
    1, 0, 0, 1, -1, 0, 0, -1,
    1, 1, 1, -1, -1, 1, -1, -1,
};
queue<node>que;
int main() {
    cin >> m >> n >> y >>x;
    for(int i =1; i <= n; i++) {
        cin >>&mmap[i][1];
    }
    que.push({n - x + 1, y, 0});
    mmap[n - x + 1][y] = '*';
    int ans;
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        ans = temp.step;
        for(int i = 0; i < 8; i++) {
            int tx = temp.x + dir[i][0];
            int ty = temp.y + dir[i][1];
            if(mmap[tx][ty] == '.') {
                mmap[tx][ty] = '*';
                que.push({tx, ty, temp.step+1});
            }
        }
    }
    cout << ans << endl;


    return 0;
}
