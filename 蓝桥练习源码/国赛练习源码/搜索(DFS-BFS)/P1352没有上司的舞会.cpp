#include<bits/stdc++.h>
using namespace std;//树形dp 
int n,sta;
int val[6010];
int root[6010];
vector<int> node[6010];
int dp[6010][2];
int low,up;

void  dfs(int cur){
	//dp[x][0]表示以x为根的子树,且x不参加舞会的最大快乐值
	//dp[x][1]表示以x为根的子树,且x参加了舞会的最大快乐值
	dp[cur][0]=0;//不选根节点 
	dp[cur][1]=val[cur];
	for(int i=0;i<node[cur].size();++i){
		int next=node[cur][i];//先计算底层的
		dfs(next);
		dp[cur][0]+=max(dp[next][0],dp[next][1]);//不选时加上每个儿子的 最大情况
		dp[cur][1]+=dp[next][0];//选择时则儿子只能加上不选儿子对的最大值 
	}
} 
int main(){
	cin>>n;
	for(int i=1;i<=n;++i) cin>>val[i];
	for(int i=1;i<n;++i){
		cin>>low>>up;
		root[low]=1;
		node[up].push_back(low);//储存子节点 
	}  
	for(int i=1;i<=n;++i){//寻找root 
		if(root[i]==0){
			sta=i;
			break;
		} 
	}
	dfs(sta);
	cout<<max(dp[sta][0],dp[sta][1]);
	
	return 0; 
} 
