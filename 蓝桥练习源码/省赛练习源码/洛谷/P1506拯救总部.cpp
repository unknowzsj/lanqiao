#include<bits/stdc++.h>
using namespace std;
//一个点超时 
int N,M;
string mps[1001];
queue<pair<int,int> > res;
int mv[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void bfs(int x,int y){
	mps[x][y]='1';
	for(int i=0;i<4;++i){
		int nx=x+mv[i][0];
		int ny=y+mv[i][1];
		if(nx<0||ny<0||nx>N+1||ny>M+1) continue;
		if(mps[nx][ny]=='0'){
			pair<int,int> nn(nx,ny);
			res.push(nn);
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
	//初始化 
	pair<int,int> strat(0,0);
	res.push(strat);
	int t=res.size();
	while(!res.empty()){
		pair<int,int> nwe=res.front();
		int nx=nwe.first;
		int ny=nwe.second;
		res.pop();
		t--;
		bfs(nx,ny);
		if(t==0){
			t=res.size();
		}
	}
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
