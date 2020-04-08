/*************************************************************************
	> File Name: 538.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月26日 星期四 02时09分59秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n, num[25][25], check[25],flag;
void func(int x) {
    //以x为起点输出
    using namespace std;
    if(flag == 1) {
        cout<<'-';
    }
    flag = 1;
    cout << x;
    for(int i = 1; i <= n; i++) {
        if(num[x][i] == 1 && check[i] == 0) {
            check[i] = 1;
            func(i);
        }
    }
}


int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> num[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        if(check[i] == 0) {
            check[i] = 1;
            func(i);
        }
    }



    return 0;
}
