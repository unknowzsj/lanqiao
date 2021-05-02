#include<bits/stdc++.h>
using namespace std;
//用数组储存会出现小错误
//数据输入不完整就会出错,会使数组不存在 
int L,N;
int main(){
	cin>>L>>N;
	int loc[N];
	for(int i=0;i<N;++i){
		cin>>loc[i];
	} 
	int mn=0;
	int mx=0;
	for(int i=0;i<N;++i){
		mn=max(mn,min(loc[i],L+1-loc[i]));
		mx=max(mx,max(loc[i],L+1-loc[i]));
	}
	cout<<mn<<" "<<mx;
	
	return 0; 
}
