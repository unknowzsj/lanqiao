#include<bits/stdc++.h>
using namespace std;
int M;
int dp[100010];
int val[18]; 
//求a的b次方 
int mi(int a,int b){
	int base=a;
	int p=b;
	int ans=1;
	while(p>0){
		if(p&1){
			ans*=base;
		}
		base*=base;
		p=p>>1;
	} 
	return ans;
}
//题目m<=100000=18^4,所以只要列举1-17的即可，可重复选 
int main(){
	cin>>M;
	for(int i=1;i<=17;++i){
		val[i]=mi(i,4);
	}
	//初始化,用fill，不要用memset 
	fill(dp,dp+M+1,M+1); 
	cout<<dp[3]<<endl; 
	dp[0]=0; 
	for(int i=1;i<=17;++i){//可重复
		for(int j=val[i];j<=M;++j){
			dp[j]=min(dp[j],dp[j-val[i]]+1);
		}
	}
	cout<<dp[M]<<endl;
	
	return 0;	
} 
