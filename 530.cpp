/*************************************************************************
	> File Name: 530.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月08日 星期三 18时08分59秒
 ************************************************************************/
#include<cstdio>
#include<iostream>
#include<queue>
#include<map>
#include<string>
#include<cstring>
using namespace std;
char mmap[55][55];
struct node{
	int x,y;
};
int dir[4][2] = {-1,0,1,0,0,-1,0,1};
int m,n,cnt;
int check[55][55];
queue<node> q;
int main(){
	cin  >> n  >> m;
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= m;++j){
			cin >> mmap[i][j];
			if(mmap[i][j] == '*'){
				q.push({i,j});
			//printf("success\n"); 
				mmap[i][j] ='.';
				check[i][j] = 1;
			}
		} 
	} 
	cin >> cnt;
	while(cnt--){
		string t;
		cin >> t;
		int dir_num;
		if(t == "NORTH"){
			dir_num = 0;
		}else if(t == "SOUTH"){
			dir_num = 1;
		}else if(t == "WEST"){
			dir_num = 2;
		}else{
			dir_num = 3;
		}
		//printf("%d\n",dir_num); 
		memset(check,0,sizeof(check));
		int times = q.size();
	//	printf("1success\n"); 
		for(int i = 0;i < times;++i){
			node tmp = q.front();
			q.pop();
			//printf("2success\n"); 
			for(int j = 1;;j++){
				int x = tmp.x + j * dir[dir_num][0];
				int y = tmp.y + j * dir[dir_num][1];
				if(mmap[x][y] != '.' )
				break;
				if(check[x][y] == 0){
					q.push({x,y});
					check[x][y] = 1;
				}
				
			}		
		}		
	}
	while(!q.empty()){
		node tmp  = q.front();
		q.pop();
		mmap[tmp.x][tmp.y] = '*';
		//printf("success\n"); 
	}	
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= m;++j){
			cout << mmap[i][j];
		} 
		cout << endl;
	} 
	
	
	
	return 0;
}

