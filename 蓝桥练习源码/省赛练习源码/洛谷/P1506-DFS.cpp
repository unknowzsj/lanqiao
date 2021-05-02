#include<bits/stdc++.h>
using namespace std;
//dfs从外面进来 ，dfs可以全部通过，bfs有一个点超时 
int N,M;
string mps[1001];
int mv[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void dfs(int x,int y){
	mps[x][y]='1';
	//遍历到结尾 
	if(x==N+1&&y==M+1) return;
	for(int i=0;i<4;++i){
		int nx=x+mv[i][0];
		int ny=y+mv[i][1];
		if(nx<0||ny<0||nx>N+1||ny>M+1) continue;
		if(mps[nx][ny]=='0'){
			dfs(nx,ny); 
		}
	}
}
int main(){
	cin>>N>>M;
	//外圈套0 
	string str=""; 
	for(int i=0;i<M+2;++i){
		str+='0';
	}
	mps[0]=str;
	mps[N+1]=str;
	for(int i=1;i<=N;++i){
		string ch;
		cin>>ch;
		mps[i]="0"+ch+"0";
	} 
	//dfs遍历
	dfs(0,0); 
	//统计 
	int cts=0;
	for(int i=0;i<=N;++i){
		for(int j=0;j<=M;++j){
			if(mps[i][j]=='0') cts++;
		}
	} 
	cout<<cts<<endl;
	
	return 0;
}
