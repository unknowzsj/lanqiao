#include<bits/stdc++.h>
using namespace std;
const int N=101;
const int M=101;
int n,m;
char a[N][M];

void dfs(int x,int y,int n,int m){
	a[x][y]='.';
	//将八个方向进行遍历(-1,0,1) 
	for(int i=-1;i<=1;++i){
		for(int j=-1;j<=1;++j){
			//自己跳过 
			if(i==0&&j==0) continue;
			//越界跳过 
			if(i+x<0||i+x>=n||j+y<0||j+y>=m) continue;
			//如果相邻的有水，继续遍历 
			if(a[i+x][j+y]=='W'){
				x+=i;
				y+=j;
				bfs(x,y,n,m);
			}
		}
	} 
} 

int main(){
	//读取输入 
	cin>>n>>m;
	for(int i=0;i<n;++i){
		string str;
		cin>>str;
		for(int j=0;j<m;++j){
			a[i][j]=str[j];
		}
	}
	//遍历每个水洼点 
	int count=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(a[i][j]=='W'){
				bfs(i,j,n,m);
				count++; 
			}
		}
	}
	cout<<count<<endl;
}
