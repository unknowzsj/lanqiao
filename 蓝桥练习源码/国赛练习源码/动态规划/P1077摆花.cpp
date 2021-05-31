#include<bits/stdc++.h>
using namespace std;//递推式推出来了，细节 需要理解 
const long long md=1000007;
int n,m;
int a[110];
int dp[110][110]; 

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	//初始化
	dp[0][0]=1; //单个时只有一种 
	//dp结构 
	for(int i=1;i<=n;++i){
		for(int j=0;j<=m;++j){
			for(int k=0;k<=min(j,a[i]);++k){//选几个i+1的盆栽 
				dp[i][j]=(dp[i][j]+dp[i-1][j-k])%md;
			}
		}
	}
	cout<<dp[n][m]%md;
	
	return 0;
} 
