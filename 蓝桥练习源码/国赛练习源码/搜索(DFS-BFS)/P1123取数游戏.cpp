#include<bits/stdc++.h>
using namespace std;//本题思路出错-想的是dfs，写的是bfs 
int t,n,m;
int num[10][10];//数据数组 
int sta[10][10];//状态数组 
int stp[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int maxs;


void dfs(int c,int d,int cur){
	cur+=num[c][d];//加上现在的所在点
	int sum=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(sta[i][j]==1) sum++;
		}
	}
	if(sum==n*m){
		maxs=max(maxs,cur);
		return;
	}
	for(int i=0;i<8;++i){
		int nc=c+stp[i][0];
		int nd=d+stp[i][1];
		//超出边界，退出 
		if(nc<0||nc>=n||nd<0||nd>=m||sta[nc][nd]==1) continue;
		sta[nc][nd]=1;//更新状态 
	}
	
	//再次遍历 
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(sta[i][j]<0){
				sta[i][j]=1;
				dfs(i,j,cur);
				sta[i][j]=-1;//回溯	
			}
		}
	} 
	
	for(int i=0;i<8;++i){
		int nc=c+stp[i][0];
		int nd=d+stp[i][1];
		//超出边界，退出 
		if(nc<0||nc>=n||nd<0||nd>=m||sta[nc][nd]==-1) continue;
		sta[nc][nd]=-1;//更新状态 
	}
}

int main(){
	cin>>t;
	 
	for(int i=0;i<t;++i){
		cin>>n>>m;
		maxs=0;
		//读取数据 
		for(int l=0;l<n;++l){
			for(int k=0;k<m;++k){
				cin>>num[l][k];
			}
		}
		//开始遍历 
		for(int a=0;a<n;++a){
			for(int b=0;b<m;++b){
				fill(sta[0],sta[0]+100,-1);//重置状态 
				sta[a][b]=1;
				dfs(a,b,0);
			} 
		}
		//输出结果 
		cout<<maxs<<endl; 
	}  
	
	return  0;
}
