#include<bits/stdc++.h>
using namespace std;
int n;
int val[110];
int dp[110],dp2[110];
int mup,mdn,mud;//最大升序列，降序列，先升后降序列
int res;

//*************不是关键*****************************
int up(int beg,int end){//最大上升序列 
	fill(dp,dp+110,0);//初始化数组
	for(int i=beg;i<=end;++i){//以i结尾的最大上升序列 
		dp[i]=1;
		for(int j=beg;j<i;++j){
			if(val[j]<val[i]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	return dp[n]; 
}
int down(int beg,int end){//最大下降序列 
	fill(dp,dp+110,0);//初始化数组
	for(int i=beg;i<=end;++i){//以i结尾的最大上升序列 
		dp[i]=1;
		for(int j=beg;j<i;++j){
			if(val[j]>val[i]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	return dp[n]; 
}
//************************************************** 

int main(){
	cin>>n;
	for(int i=1;i<=n;++i) cin>>val[i];
	for(int i=1;i<=n;++i){//以i结尾的最大上升序列 
		dp[i]=1;
		for(int j=1;j<i;++j){
			if(val[j]<val[i]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	for(int i=n;i>=1;--i){//以i结尾的反向最大上升序列 
		dp2[i]=1;
		for(int j=n;j>i;--j){
			if(val[j]<val[i]){
				dp2[i]=max(dp2[i],dp2[j]+1);
			}
		}
	}
	//找到最大 
	for(int i=1;i<=n;++i){
		res=max(res,dp[i]+dp2[i]-1);//自己重复加了 
	}
	cout<<n-res;
	
	return 0;
} 
