#include<bits/stdc++.h>
using namespace std;
const long long bas=20201114;
long long res;
int k,p,l;

void dfs(int n,int pre){
	if(n==0){//剩下0步 
		res++;
		res%=bas;
		return; 
	}
	
	for(int i=1;i<=k;++i){
		if((pre>=p&&i>=p)||n-i<0) continue;//连续两次大于p或者步数不够，则跳过
		else{
			dfs(n-i,i);
		} 
	}
}
int main(){
	cin>>k>>p>>l;
	//开始遍历
	dfs(l,-1);//前面一步为-1
	cout<<res;
	
	return 0; 
}
