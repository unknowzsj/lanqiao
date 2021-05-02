#include<bits/stdc++.h>
using namespace std;
//这题和最长子序列类似 
int N;
int dp[10001];
int a[10001];//前i个的和 
int sum;
int main(){
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	if(a[N]<0){
		cout<<"Impossible"<<endl;
		exit(0);
	}
	dp[0]=0;
	for(int i=1;i<=N;++i){
		for(int j=0;j<i;++j){//在前i-1中找到最长 
			//如果a[i]>=a[j]代表j-i这一段可以成为一段 
			//只有a[i]>=0时才有选择的可能 
			if(a[i]>=0&&a[i]>=a[j]) dp[i]=max(dp[i],dp[j]+1); 
		}
	}
	cout<<dp[N]<<endl;
	
	return 0;
} 
