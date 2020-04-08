/*************************************************************************
	> File Name: 540.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月26日 星期四 02时23分07秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int n, cost, num[45];
int set[2][2100000],cnt[2];
void func(int set_num, int start, int end, int sum) {
    //set_num 是两个分组的编号
    if(sum > cost) return;
    for(int i = start; i < end; i++ ) {
        sum += num[i];
        set[set_num][cnt[set_num]] = sum;
        cnt[set_num]++;//每个组的计数器
        func(set_num, i + 1, end, sum);
        sum -= num[i];
    }
}

int main() {
    while(cin >> n >> cost) {
        cnt[0] = cnt[1] = 0;
        for(int i = 0; i < n; i++) {
            cin >> num[i];
        }
        func(0, 0,n >> 1,0);
        func(1, n >> 1,n, 0);
        sort(set[1],set[1] + cnt[1]);
        int flag = 0;
        for(int i = 0; i < cnt[0]; i++) {
            int target = cost - set[0][i];
            int l = 0, r = cnt[0] - 1;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(set[1][mid] == target) {
                    cout << "YES"<<endl;
                    flag = 1;
                    break;
                }
            
            if(set[1][mid] < target) {
                l = mid + 1;
            }
            if(set[1][mid] > target) {
                r = mid - 1;
            }
        }
            if(flag == 1) break;
        }
        if(flag == 0) {
            cout << "NO"<<endl;
        }
    
    
    }


    return 0;
}
