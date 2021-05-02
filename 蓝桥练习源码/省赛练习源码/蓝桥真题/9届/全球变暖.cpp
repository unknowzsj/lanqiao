#include<bits/stdc++.h>
using namespace std;
string mps[100];
int cts;
int N;
int mv[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
int dfs(int a,int b){
	for(int i=0;i<4;++i){
		int x=a+mv[i][0];
		int y=b+mv[i][1];
		if(x<0||y<0||x>N||y>N) continue;
		if(mps[x][y]=='#'){
			mps[x][y]='o';
			dfs(x,y);
		}
	} 
}
int main(){
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>mps[i];
	}
	//进行淹没 
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(mps[i][j]=='.'){
				for(int k=0;k<4;++k){
					int x=i+mv[k][0];
					int y=j+mv[k][1];
					if(x<0||y<0||x>N||y>N) continue;
					if(mps[x][y]=='#') mps[x][y]='o';
				}	
			} 			
		} 
	}
	//进行数岛
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(mps[i][j]=='#'){
				mps[i][j]='o';
				cts++;
				dfs(i,j);
			}
		}
	} 
	cout<<cts<<endl;
	
	return 0;
}
