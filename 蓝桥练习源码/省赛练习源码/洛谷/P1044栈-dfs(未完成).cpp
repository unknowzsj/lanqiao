#include<bits/stdc++.h>
using namespace std;
//未完成 
//栈输出的组合只有一种方式得到，不用管记录结果
int cts;
int n; 
void dfs(int pu,int po,int& cur){
	//入栈出栈均完毕则种类+1 
	if(cur==0){
		cts++;
		return;
	}else if(po>n||pu>n){
		return;
	}
	//入栈必须大于等于出栈 
	if(pu>=po){
		//入栈操作
		int pu1=pu+1;
		int po1=po;
		cur--;
		dfs(pu1,po1,cur);
		//出栈操作 
		int pu2=pu;
		int po2=po+1;
		cur++;
		dfs(pu2,po2,cur);
	}
} 

int main(){
	cin>>n;
	dfs(0,0,n);
	cout<<cts<<endl;
	
	return 0;
}
