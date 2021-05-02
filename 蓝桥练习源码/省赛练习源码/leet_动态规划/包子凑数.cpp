#include<bits/stdc++.h>
using namespace std;
int N,max;
int dp[10010]; 
//最大公约数 
int gcb(int a,int b){
	if(b==0) return a;
	return gcb(b,a%b); 
} 

int main(){
	cin>>N;
	int  vol[N];
	for(int i=0;i<N;++i) cin>>vol[i];
	//通过最大公约数=1求是否无限多 
	int d=0;
	for(int i=0;i<N;++i){
		d=gcb(vol[i],d);	
	}
	if(d!=1){
		cout<<"INF"<<endl;
		return 0;
	}
	//通过计算可以凑出的数计算
	fill(dp,dp+10010,-1);
	//初始化
	dp[0]=1;
//	for(int i=0;i<N;++i){
//		dp[vol[i]]=1;
//	} 
	//计算非基础数 
	for(int i=0;i<10010;++i){
		for(int j=0;j<N;++j){
			//==1，清楚条件，数组会出现变化 
			if(dp[i-vol[j]]==1) dp[i]=1;
		} 
	}
	int sum=0;
	for(int i=0;i<10010;++i) if(dp[i]!=1) sum++;
	cout<<sum<<endl;
	
	return 0; 
} 
