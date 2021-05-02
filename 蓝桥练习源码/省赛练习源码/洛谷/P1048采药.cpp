#include<bits/stdc++.h>
using namespace std;

int T,M;
int main(){
	cin>>T>>M;
	int a[M+1][2]={0};
	//初始化完成 
	int dp[M+1][T+1]={0};
	for(int i=1;i<=M;++i){
		//0-时间，1-价值 
		cin>>a[i][0]>>a[i][1];
	}
	//更新dp 
	for(int i=1;i<=M;++i){
		//j从大到小，防止重复选取 
		for(int j=T;j>=0;--j){
			if(j>=a[i][0]){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i][0]]+a[i][1]);
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	cout<<dp[M][T]<<endl;
	
	return 0;
} 
