#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,s,t;
ll dp[1000010];//数组设置的大一点  

int main(){
	cin>>m>>s>>t;
	//初始化
	dp[0]=0; 
	//进行dp,单层循环，遍历每秒,计算闪现的方式 
	for(int i=1;i<=t;++i){
		if(m>=10){//魔法值足够
			dp[i]=dp[i-1]+60;
			m-=10;//更新魔法值 
		}
		else{//缺蓝 
			dp[i]=dp[i-1];
			m+=4; 
		} 
	}
	//第二次只要计算走路是否更快并进行结果判断就行了 
	for(int i=1;i<=t;++i){
		if(dp[i]<dp[i-1]+17) dp[i]=dp[i-1]+17;//走路更快，选择走路 
		if(dp[i]>=s){
			cout<<"Yes"<<endl<<i;
			return 0;
		}
	}
	cout<<"No"<<endl<<dp[t];
	
	return 0;
} 
