#include<bits/stdc++.h>
using namespace std;

int n,k;
int main(){
	cin>>n>>k;
	int dp[n+1]={0};
	dp[1]=1;
	dp[2]=2;
	//dp—≠ª∑ 
	for(int i=3;i<=n;++i){
		for(int j=1;j<=k;++j){
			if(i>=j) dp[i]=(dp[i]+dp[i-j])%100003;
		}
	} 	
	cout<<dp[n]%100003<<endl;
	
	return 0;
} 
