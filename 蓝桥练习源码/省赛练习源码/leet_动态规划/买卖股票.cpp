#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
	cin>>n;
	int dp[n];
	int price[n]; 
	for(int i=0;i<n;++i){
		cin>>price[i];
	}
	dp[0]=0;
	int min=price[0];
	//通过最小值计算，可以不用数组 
	if(n<=1) cout<<0<<endl;
	for(int i=1;i<n;++i){
		dp[i]=max(dp[i-1],price[i]-min);
		if(dp[i]<0) dp[i]=0;
		if(min>price[i]) min=price[i];
	}
	cout<<dp[n-1]<<endl;
	
	return 0;
} 
