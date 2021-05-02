#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//未完成 
int N,K;
int main(){
	cin>>N>>K;
	ll max_v[N][K+1],min_v[N][K+1];
	int value[N];
	const ll big=1000000009;
	//读取输入
	for(int i=0;i<N;++i){
		cin>>value[i];
		
	}
	sort(value,value+N);
	//初始化 
	for(int i=0;i<N;++i){
		max_v[i][0]=0;
		min_v[i][0]=0;
	}
	for(int i=1;i<=K;++i){
		for(int j=0;j<N;++j){
			if(j-i<=-2){
			 max_v[j][i]=0;
			 min_v[j][i]=0;
			}
		}
	}
	//dp更新 
	max_v[0][1]=value[0];
	min_v[0][1]=value[0];
	for(int k=1;k<=K;++k){
		for(int i=1;i<N;++i){
			max_v[i][k]=max(max_v[i-1][k],max(min_v[i-1][k-1]*value[i],max_v[i-1][k-1]*value[i]));
			min_v[i][k]=min(min_v[i-1][k],min(max_v[i-1][k-1]*value[i],min_v[i-1][k-1]*value[i]));
		}
	}
	int Max=0;
	int Min=INT_MAX;
	for(int i=0;i<N;++i){
		if(Max<max_v[i][K]%big) Max=max_v[i][K]%big;
		if(Min>min_v[i][K]%big) Min=(-min_v[i][K])%big;
	}
	cout<<(Min>Max ? Min:Max)<<endl;
	
	return 0;
}
