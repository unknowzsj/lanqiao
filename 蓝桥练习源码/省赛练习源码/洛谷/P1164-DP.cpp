#include<bits/stdc++.h>
using namespace std;

int dp[10001][10001];
int mony[10001];
int N,M;
int main(){
	//输入 
	cin>>N>>M;
	for(int i=1;i<=N;++i){
		cin>>mony[i];
	} 
	//
	for(int i=1;i<=N;++i){
		for(int j=M;j>0;--j){
			if(j>mony[i]) dp[i][j]=dp[i-1][j]+dp[i-1][j-mony[i]];
			else if(j==mony[i]) dp[i][j]=dp[i-1][j]+1;//多一种选择
			else dp[i][j]=dp[i-1][j];//无法选择 
		}
	}
	cout<<dp[N][M]<<endl;
	
	return 0;
} 
