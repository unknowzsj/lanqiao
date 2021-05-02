#include<bits/stdc++.h>
using namespace std;

int n,m;
int main(){
	cin>>n>>m;
	int a[m+1][2]={0};
	int dp[n+1]={0};
	for(int i=1;i<=m;++i){
		//0-价值，1-重要度 
		cin>>a[i][0]>>a[i][1];
	}
	
	for(int i=1;i<=m;++i){
		for(int j=n;j>=a[i][0];--j){
			dp[j]=max(dp[j],dp[j-a[i][0]]+a[i][0]*a[i][1]);
		}
	} 
	cout<<dp[n]<<endl;
	
	return 0;
} 
