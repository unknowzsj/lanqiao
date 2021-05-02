#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
ll T,N;
ll dp[10000010];//数组一般开这么大，不会出错 
ll t[1000001];
ll v[1000001];
//时间外圈，两个点超时
//物品外圈，通过，重复-时间正序，不重复-时间逆序 
int main(){
	cin>>T>>N;
	for(ll i=1;i<=N;++i){
		cin>>t[i]>>v[i];
	}
	//i为物品，j为时间 
	for(ll i=1;i<=N;++i){
		//正向枚举时间
		//不重复的选择逆向枚举 
		for(ll j=t[i];j<=T;++j){
			//如果时间大于所花时间 
			dp[j]=max(dp[j],dp[j-t[i]]+v[i]); 
		}
	}
	cout<<dp[T]<<endl;
	
	return 0;
} 
