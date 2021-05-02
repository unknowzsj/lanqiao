#include<bits/stdc++.h>
using namespace std;

int n,m;
int main(){
	cin>>n>>m;
	int a[m+1][2]={0};
	int dp[m+1][n+1]={0};
	for(int i=1;i<=m;++i){
		//0-价值，1-重要度 
		cin>>a[i][0]>>a[i][1];
	}
	
	for(int i=1;i<=m;++i){
		for(int j=n;j>=0;--j){
			if(j>=a[i][0]){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i][0]]+a[i][0]*a[i][1]);
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	} 
	cout<<dp[m][n]<<endl;
	
	return 0;
} 
