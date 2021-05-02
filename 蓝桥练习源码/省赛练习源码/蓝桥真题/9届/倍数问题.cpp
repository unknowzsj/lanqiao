#include<bits/stdc++.h>
using namespace std;//大的数超时,不考虑拿所有分 
typedef long long ll; 
ll N,K;
ll num[100010];
ll maxs;
void dfs(int cur,int flag,ll sum){
	if(flag==3){
		if(sum%K==0&&sum>maxs) maxs=sum;
		return;
	}
	if(cur>N) return;
	//不选cur
	int cur1=cur+1;
	int flag1=flag; 
	ll sum1=sum;
	dfs(cur1,flag1,sum1);
	//选cur 
	int cur2=cur+1;
	int flag2=flag+1;
	ll sum2=sum+num[cur];
	dfs(cur2,flag2,sum2);
}
int main(){
	cin>>N>>K;
	for(ll i=1;i<=N;++i){
		cin>>num[i];
	}
	dfs(1,0,0);
	cout<<maxs<<endl;
	
	return 0;
} 
