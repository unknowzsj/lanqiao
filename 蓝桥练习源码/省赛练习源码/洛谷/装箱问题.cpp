#include<bits/stdc++.h>
using namespace std;

int v,n;
int main(){
	cin>>v;
	cin>>n;
	int a[n+1]={0};
	//dp[j]=容量为j时能装下的最大值 
	int dp[v+1]={0};
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	//初始化
	dp[0]=0;
	//对于每一个物体，遍历所有的容量，看是否放的下
	//为了物体只能选取一个，物体放在外层 
	for(int i=1;i<=n;++i){
		//从大到小是为了不重复
		/*
			从小到大
			若j=2a[i]
			dp[a[i]]选取i
			dp[j]会选取i两次 
		*/ 
		//j最小为物体的体积 
		for(int j=v;j>=a[i];--j){
			//选和不选物体i
			//不选则为自身 
			dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
		}
	}
	//输出最小剩余 
	cout<<v-dp[v]<<endl;
	
	return 0;
} 
