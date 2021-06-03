#include<bits/stdc++.h>
using namespace std;
typedef long long ll;//完全背包，注意输出要用longlong 
int v,n;
ll a[30];
ll dp[10010];//构造j的值的最大种类 

int main(){
	cin>>v>>n;
	for(int i=1;i<=v;++i) cin>>a[i];
	sort(a,a+v);//从小到大排序
	//初始化
	dp[0]=1; 
	//dp开始遍历 
	for(int i=1;i<=v;++i){
		for(int j=a[i];j<=n;++j){
			dp[j]+=dp[j-a[i]];
		}
	} 
	cout<<dp[n];
	
	return 0;
}
