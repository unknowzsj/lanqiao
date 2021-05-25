#include<bits/stdc++.h>
using namespace std;//本题思路出错-想的是dfs，写的是bfs 
int t,n,m;
int num[10][10];//数据数组 
int sta[10][10];//状态数组 
int stp[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int maxs,sum;


void dfs(int x,int y){
	//搜索通过不断的加y 
	if(y==m+1){//当边界时 
		dfs(x+1,1);
		return;
	} 
	if(x==n+1){//搜索结束 
		maxs=max(maxs,sum);
		return;
	} 
	
	//选取该位置
	if(sta[x][y]==0){//未被选取和在选取的周围 
		sum+=num[x][y];
		sta[x][y]=1; 
		for(int i=0;i<8;++i){
			int nx=x+stp[i][0];
			int ny=y+stp[i][1]; 
			++sta[nx][ny];//更新状态,这里通过++/--的方式防止覆盖区域被整体回溯 
		}
		
		dfs(x,y+1);
		
		//回溯
		sum-=num[x][y];
		sta[x][y]=0; 
		for(int i=0;i<8;++i){
			int nx=x+stp[i][0];
			int ny=y+stp[i][1];
			--sta[nx][ny];//更新状态
		} 
	} 
	
	//不选该位置
	dfs(x,y+1);
}

int main(){
	cin>>t;
	 
	for(int i=0;i<t;++i){
		//初始化数组 
		fill(num[0],num[0]+100,0);
		fill(sta[0],sta[0]+100,0);
		cin>>n>>m;
		//读取数据 
		for(int l=1;l<=n;++l){
			for(int k=1;k<=m;++k){
				cin>>num[l][k];
			}
		}
		//开始遍历
		maxs=0;
		dfs(1,1); 
		//输出结果 
		cout<<maxs<<endl; 
	}  
	
	return  0;
}
