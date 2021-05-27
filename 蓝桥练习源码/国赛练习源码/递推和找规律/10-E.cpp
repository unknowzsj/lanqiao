#include<bits/stdc++.h>
using namespace std;//未完成 
int res;
int num[110];

bool sqr(int n){//判断是否是完全平方 
	for(int i=0;i*i<=n;++i){
		if(i*i==n) return true;
	}
	return false;
}
void dfs(int cur,int cts){
	if(cur==100){//遍历到100，判断并退出 
		res=max(cts,res);
		return;
	}
	//不选cur
	dfs(cur+1,cts);
	//选cur
	if(!sqr(cur)){//cur不是完全平方数 
		int flag=0;
		for(int i=2;i<cur;++i){//判断是否可以放进去 
			if(num[i]==1&&sqr(cur+i)){//选中了该数,且该数相加是完全平方 
				flag=1;
				break; 
			}			
		}
		if(flag==0){
			num[cur]=1;
			dfs(cur+1,cts+1);
			num[cur]=0;//回溯 
		} 
	} 
}
int main(){
	//初始遍历 
	dfs(2,0);
	cout<<res;
	
	return 0;
}
