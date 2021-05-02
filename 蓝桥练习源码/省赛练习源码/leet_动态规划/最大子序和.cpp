#include<bits/stdc++.h>
using namespace std;

int n;
int main(){
	cin>>n;
	int dp[n];
	int val[n];
	for(int i=0;i<n;++i){
		cin>>val[i];
	}
	dp[0]=val[0];
	
	for(int i=1;i<n;++i){
		if(dp[i-1]<0) dp[i]=val[i];
		else dp[i]=dp[i-1]+val[i];
	}
	
	int max=INT_MIN;
	for(int j=0;j<n;++j){
		if(max<dp[j]) max=dp[j];
	} 
	cout<<max<<endl;
	
	return 0;
} 
