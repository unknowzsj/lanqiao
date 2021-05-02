#include<bits/stdc++.h>
using namespace std;
int N,M;
string mps[10000];
int mv[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void dfs(int n,int m){
	//n行m列 
	mps[n][m]='0';
	for(int i=0;i<4;++i){
		int nn=n+mv[i][0];
		int nm=m+mv[i][1];
		//找到联通的继续dfs
		if(nn<0||nm<0||nn>=N||nm>=M) continue;//越界 
		if(mps[nn][nm]!='0'){
			dfs(nn,nm);
		}
	}
}

int main(){
	cin>>N>>M;
	int cts=0;
	//输入地图 
	//x-列-m，y-行-n
	for(int i=0;i<N;++i){
		cin>>mps[i];
	} 
	//遍历每个点，并将其联通区变为0
	//i-y行,j-x列 
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(mps[i][j]!='0'){
				dfs(i,j);
				//一个点找到没有时便代表找到一个细胞 
				cts++; 
			}
		}
	}
	cout<<cts<<endl;
	
	return 0; 
}
