#include<bits/stdc++.h>
using namespace std;
int n,m; 
int res;
int dp[50][50]; 

int main(){
	cin>>n>>m;
	//初始化
	dp[1][0]=1; 
	//dp主体 
	for(int j=1;j<=m;++j){
		for(int i=1;i<=n;++i){
			if(i==1) dp[i][j]=dp[n][j-1]+dp[2][j-1];
			else if(i==n) dp[i][j]=dp[1][j-1]+dp[n-1][j-1];
			else dp[i][j]=dp[i-1][j-1]+dp[i+1][j-1];
		}
	} 
	cout<<dp[1][m]<<endl; 
	
	return 0;
}
