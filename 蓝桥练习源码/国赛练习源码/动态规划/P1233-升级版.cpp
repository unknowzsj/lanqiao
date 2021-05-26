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

//O(nlogn)，升级版 
int main(){
	cin>>n;//读取数据 
	for(int i=0;i<n;++i) cin>>val[i].len>>val[i].wid;
	sort(val,val+n,cpa);//对长度进行排序
	
	//长度为 i的序列，结尾越小越好
	int len=0; 
	dp[0]=val[0].wid;
	for(int i=1;i<n;++i){//寻找最长上升子序列 
		if(val[i].wid>dp[len]) dp[++len]=val[i].wid;
		else *lower_bound(dp,dp+len+1,val[i].wid)=val[i].wid;
	} 
	cout<<len+1;
	
	return 0;
}
