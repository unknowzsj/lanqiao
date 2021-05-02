#include<bits/stdc++.h>
using namespace std;
int V,G;
int need[1001];//所需营养 
int val[1001][1001];//含有的营养
int res[1001];//储存的答案 
int chs[1001];//每次选择的编号
int mn=100001;//选择的最少包数 
//dfs选择时就是回溯的用法
//此题关键：dfs递归对每个饲料包进行选择 
//s为选择的包数 
bool ok(int s){
	for(int i=1;i<=V;++i){
		int sum=0;
		for(int j=1;j<=s;++j){
			sum+=val[chs[j]][i];
		}
		if(sum<need[i]) return false;
	} 
	return true;
}
//cur-当前第几包，s-选择的包数 
void dfs(int cur,int s){
	//遍历到最后一个位置退出 
	if(cur>G){
		//选择的包可以达到要求 
		if(ok(s)){//现在的选的少 
			if(s<mn){
				mn=s;
				for(int i=1;i<=mn;++i) res[i]=chs[i]; 
			} 
		}
		return;//返回 
	} //选择放前面保证字典序最小 
	//选择cur包
	chs[s+1]=cur;
	cur++;s++;
	dfs(cur,s);
	chs[s]=0;s--;//回溯
	//不选择cur包
	dfs(cur,s); 
}
int main(){
	//读取输入 
	cin>>V;
	for(int i=1;i<=V;++i){
		cin>>need[i];
	}
	cin>>G;
	for(int i=1;i<=G;++i){
		for(int j=1;j<=V;++j){
			cin>>val[i][j];
		}
	}
	//位置1,选择0 
	dfs(1,0); 
	//输出结果 
	cout<<mn;
	for(int i=1;i<=mn;++i){
		cout<<" "<<res[i]; 
	} 
	cout<<endl;
	 
	return 0;
} 
