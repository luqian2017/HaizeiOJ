/*************************************************************************
	> File Name: 529.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月01日 星期三 20时32分48秒
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int n, m, check[150][150];
char mmap[150][150];
int dir[8][2] = {
    0, 1, 1, 0, 0, -1, -1, 0,
    1, 1, 1, -1, -1, -1, -1, 1
};
struct node {
    int x, y, s;
};

int func() {
    int a, b, c, d;
    cin >>c >> d >> a >> b;
    check[a][b] = 1;
    if(!a) return 0;
    memset(check, 0, sizeof(check));
    for(int i = 0; i < 8; i++) {
        for(int j = 1; 1; j++) {
            int x = c + j*dir[i][0];
            int y = d + j*dir[i][1];
            if(mmap[x][y] != 'O') break;
            check[x][y] = 2;//表示可以直接击杀
        }
    }
    check[c][d] = 2;
    if(check[a][b] == 2) {
        cout << 0 << endl;
        return 1;
    }
    queue<node> que;
    que.push({a,b,0});
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        for(int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if(check[x][y] == 2) {
                cout << temp.s+1 << endl;
                return 1;
            }
            if(mmap[x][y] == 'O' && check[x][y] != 1) {
                check[x][y] = 1;
                que.push({x, y, temp.s+1});
            }
        }
    }
    cout << "Impossible!" << endl;
    return 1;
}

int main() {
  cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >>&mmap[i][1];
    }
    while(func()) {
        
    }



    return 0;
}

