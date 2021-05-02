#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	int mx=0;
	int val[n+1][n+1]={0};
	int dp[n+1][n+1]={0};
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			cin>>val[i][j];
			//取可以到i，j的最大值+(i,j)的值
			dp[i][j]=val[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
			if(dp[i][j]>mx) mx=dp[i][j]; 
		}
	}
	cout<<mx<<endl;
	
	return 0;
}
