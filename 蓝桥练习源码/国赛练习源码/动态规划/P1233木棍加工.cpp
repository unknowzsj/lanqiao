#include<bits/stdc++.h>
using namespace std;
struct Val{//需要对单独的进行排序 
	int len;
	int wid;
}val[5001]; 
bool cpa(Val a,Val b){//自定义的比较函数 
	return a.len>b.len;//这里是>,降序排列 
} 
int n,dp[5002];
int t;

//普通dp 
int main(){
	cin>>n;//读取数据 
	for(int i=0;i<n;++i) cin>>val[i].len>>val[i].wid;
	sort(val,val+n,cpa);//对长度进行排序
	
	//以i为结尾的最长上升子序列 
	for(int i=0;i<n;++i){//寻找最长上升子序列 
		dp[i]=1;
		for(int j=i-1;j>=0;--j){//反序防止重复，背包问题常用 
			if(val[j].wid<val[i].wid) dp[i]=max(dp[i],dp[j]+1);
		}
		t=max(t,dp[i]);//找寻最大 
	} 
	cout<<t;
	
	return 0;
}
