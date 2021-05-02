#include<bits/stdc++.h>
using namespace std;
//迭代或循环dp 
int n;
int dp[100000];
int main(){
	cin>>n;
	//初始化 
	dp[1]=1;
	dp[2]=2;
	dp[3]=2;
	for(int i=4;i<=n;i++){
		for(int j=1;j<=i/2;++j){
			dp[i]+=dp[j];
		}
		//加上自身 
		dp[i]++;
	} 
	cout<<dp[n]<<endl;
	
	return 0;
}
