#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010];
int stu[100010];//未完成 
int mx;

void dfs(int sum,int cur){
	if(cur>n){
		mx=max(mx,sum);
		return;
	}
	//不选cur
	dfs(sum,cur+1);
	
	//选cur
	if(!stu[a[cur]]&&!stu[a[cur]+1]&&!stu[a[cur]-1]){
		stu[a[cur]+1]=1;//不能选+1
		stu[a[cur]-1]=1;//不能选-1				
		dfs(sum+a[cur],cur+1);
		stu[a[cur]+1]=0;//回溯 
		stu[a[cur]-1]=0;	
	} 
}

int main(){
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	dfs(0,1);//从位置1开始遍历 
	cout<<mx;
	
	return 0;
}

//if(flag){
//			for(int i=1;i<cur;++i){
//			if(stu[a[i]]) ns-=a[i];//将前面的不可取数取消 
//			}
//		}
