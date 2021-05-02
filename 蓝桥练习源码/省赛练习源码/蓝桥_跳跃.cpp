#include<bits/stdc++.h>
using namespace std;
//trans为标志位 
int n,m,trans;

int main(){
	//动态规划，从小开始计算 
	cin>>n>>m;
	int map[n+1][m+1];
	//每个点可以取得位置坐标，想上倒数 
	//可以跳格子 
	int x[9]={ 0, 0, 0,-1,-1,-1,-2,-2,-3};
	int y[9]={-1,-2,-3, 0,-1,-2, 0,-1, 0};
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>map[i][j];
			trans=INT_MIN;
			for(int t=0;t<9;++t){
				if(i+x[t]>0 && j+y[t]>0){
					trans=max(trans,map[i+x[t]][j+y[t]]);
				}
			}//INT_MIN是无穷小 
			if(trans!=INT_MIN)  map[i][j]+=trans;
		} 
	}
	cout<<map[n][m]<<endl;
	
	return 0;
}
