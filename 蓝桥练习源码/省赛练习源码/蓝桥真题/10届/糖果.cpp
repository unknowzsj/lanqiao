#include<iostream>
#include<set>
using namespace std;;
//状压dp
//子集法--可能会超时 
int N,M,K;
set<int> sum;

int  main(){
	cin>>N>>M>>K;
	int dp[N+1][M+1]={0};
	int val[N+1][K]={0};
	//统计每一包的口味 
	for(int i=1;i<=N;++i){
		for(int j=0;j<K;++j){
			cin>>val[i][j];
		}
	}
	//初始化
	for(int i=0;i<K;++i){
		sum.insert(val[1][i]);
	}
	//统计第一包时的味道数量 
	int str=sum.size();
	cout<<str<<endl;
	dp[1][0]=0;
	dp[1][str]=1; 
	//dp更新 
	for(int i=2;i<=N;++i){
		int str1=sum.size();
		for(int l=0;l<K;++l){
			sum.insert(val[i][l]);
		}
		//购买第i包时的口味总量 
		int str2=sum.size();
		//购买第i时增加的量 
		int cha=str2-str1;
		cout<<cha<<endl;
		for(int j=0;j<=M;++j){
			if(j-cha>=0&&dp[i-1][j]>0&&dp[i-1][j-cha]){
				dp[i][j]=min(dp[i-1][j],dp[i-1][j-cha]+1);
			} 
		}
	}
	//找到口味为M个的最小包数 
	int min=N+1;
	for(int i=1;i<=N;++i){
		if(dp[i][M]<min) min=dp[i][M];
	}
	cout<<min<<endl;
	
	return 0;
}
