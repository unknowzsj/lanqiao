#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
	cin>>n;
	int dp[n+1];
	for(int i=0;i<3;++i){
		dp[i]=i;
	}
	
	for(int i=3;i<n+1;++i){
		dp[i]=dp[i-1]+dp[i-2];
	}
	cout<<dp[n]<<endl;
} 
