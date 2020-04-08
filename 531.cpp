/*************************************************************************
	> File Name: 531.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月08日 星期三 18时49分04秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
struct node {
    int status, step;
};
int n, num[25], arr[25][25], check[2200000];

void init() {
    int t = 1;
    for(int i = 0; i < 21; i++) {
        num[i] = t;
        t *= 2;//按位赋值
    }
}

int main() {
    init();//位运算的方式表示状态，，例如t_mode
    cin >> n;
    int start_status = 0;
    for(int i = 1; i <= n; i++) {
        int t;
        cin >> t;
            if(t == 1) {
            start_status += num[i];
            }
    }
        for(int i = 1; i <= n; i++) {
            cin >> arr[i][0];
            for(int j = 1; j <= arr[i][0]; j++) {
                cin >> arr[i][j];
                arr[i][24] += num[arr[i][j]];//arr[i][24]存放每次状态
            }
        }
    
    queue<node>que;
    que.push({start_status,0});
    check[start_status] = 1;
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        if(temp.status == 8) {//2^3 = 8
            cout << temp.step << endl;
            return 0;
        }
        for(int i = 1; i <= n; i++) {
            if( (temp.status & num[i]) == 0 ) {//按钮没有被按下取的时候
                int status_temp = temp.status + num[i];//将每种情况试以下
                status_temp &= ~(arr[i][24]);
                if(!check[status_temp]) {
                    check[status_temp] = 1;
                    que.push({status_temp,temp.step+1});
                }
            }
        }
    }


    return 0;
}
