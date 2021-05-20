#include<bits/stdc++.h>
using namespace std;//本题考虑的编号为顺序1-n 
int n,m;
int node[21][21];
int maxlen;
int bol[21];

void dfs(int nn,int dis){
	//不需要判断是否走完 
	maxlen=max(maxlen,dis);
	//开始dfs 
	for(int i=1;i<=n;++i){
		if(node[nn][i]&&!bol[i]){//存在通路，有距离
			bol[i]=true;
			dfs(i,dis+node[nn][i]);
			bol[i]=false;//回溯 
		} 
	} 
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int a,b,l;
		cin>>a>>b>>l;
		node[a][b]=l;//记录相邻节点的距离 
		node[b][a]=l;
	}
	
	for(int i=1;i<=n;++i){
		bol[i]=true; 
		dfs(i,0);
		bol[i]=false;
	} 
	cout<<maxlen;
	
	return 0;
}
