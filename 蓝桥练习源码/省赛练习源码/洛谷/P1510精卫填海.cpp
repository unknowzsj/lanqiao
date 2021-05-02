#include<bits/stdc++.h>
using namespace std;
//关键点：体力是限制，而不是体积
//所以用体力和物品数来作为状态
//该体力下可以达到的最大体积
//二维数组三道题超出了空间限制 
int V,N,C;
int main(){
	cin>>V>>N>>C;
	int dp[N+1][C+1]={0};
	int val[N+1][2]={0};
	//0-体积，1-体力 
	for(int i=1;i<=N;++i){
		cin>>val[i][0]>>val[i][1];
	} 
	//初始化
	for(int i=0;i<=C;++i){
		dp[0][i]=0;
	} 
	//更新dp
	for(int i=1;i<=N;++i){
		//从大到小，防止重复 
		for(int j=C;j>0;--j){
			if(j>=val[i][1]){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-val[i][1]]+val[i][0]);
			}else dp[i][j]=dp[i-1][j]; 
		}
	} 
	//判断是否可以 
	int min=C+1;
	if(dp[N][C]>=V){
		for(int i=0;i<=C;i++){
			if(dp[N][i]>=V){
				min=i;
				break;
			}
		}
		cout<<C-min<<endl;
	}else cout<<"Impossible"<<endl;
	
	return 0;
}
