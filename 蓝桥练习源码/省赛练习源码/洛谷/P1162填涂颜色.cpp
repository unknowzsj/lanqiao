#include<bits/stdc++.h>
using namespace std;
//最外圈加0 
int mps[32][32];
int n;
queue<pair<int,int> > res;
map<pair<int,int>,bool> flag;
int mv[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void bfs(int x,int y){
	for(int i=0;i<4;++i){
		int nx=x+mv[i][0];
		int ny=y+mv[i][1];
		//越界 
		if(nx<0||ny<0||nx>n+1||ny>n+1) continue;
		//更新 
		if(mps[nx][ny]!=1){
			mps[nx][ny]=0;
			pair<int,int> nl(nx,ny);
			//防止走重复的路 
			if(!flag[nl]){
				flag[nl]=true;
				res.push(nl);
			}
		} 
	}
} 
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>mps[i][j];
			//用2填充所有0 
			if(mps[i][j]==0) mps[i][j]=2; 
		} 
	}
	
	pair<int,int> start(0,0);
	res.push(start);
	flag[start]=true;
	int t=res.size();
	while(!res.empty()){
		pair<int,int> nlc=res.front();
		int nwx=nlc.first;
		int nwy=nlc.second;
		res.pop();
		t--; 
		bfs(nwx,nwy);
		if(t==0){
			t=res.size();
		}
	}
	//输出 
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cout<<mps[i][j]<<" ";
		}
		cout<<endl;
	} 
} 
