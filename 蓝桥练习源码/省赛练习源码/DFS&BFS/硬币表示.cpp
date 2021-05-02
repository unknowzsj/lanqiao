#include<bits/stdc++.h>
using namespace std;
/*
	硬币表示：有1，5，10，25面值的硬币组成n的组合的总数 
*/
int coin[4]={1,5,10,25};
//思路：一个数由几个最大的组成 
int sumcoin(int n,int *coin,int cur){
	//初始化
	if(cur==0) return 1; 
	int res=0;
	for(int i=0;i*coin[cur]<=n;i++){
		//下一层的最大数坐标减一 
		//函数的参数用变量，不要用表达式 
		int shengyu=n-i*coin[cur];
		res+=sumcoin(shengyu,coin,cur-1); 
	}
	return res;
} 
int main(){
	//最大数的坐标为3
	int n=20; 
	int out=sumcoin(n,coin,3);
	cout<<out<<endl;
	 
	return 0;
}  
