#include<bits/stdc++.h>
using namespace std;
//有点复杂，有空再看 
int N;
string str="s";//项链 
int dp[10001];//dp值 
int mx;//暂存中部最长的 
int res;//所有最长的 
void dfs(int cur,int maxl){
	int diff=1;
	for(int i=cur;i<=N;++i){
		if(str[cur]==str[cur-1]||str[cur]='w'||diff==1){
			dp[cur]=
		}
	} 
}
int main(){
	//读取输入
	string ch; 
	cin>>N>>ch;
	str+=ch;//为了使坐标对应 
	dp[0]=0;
	dp[1]=1;
	dfs(2,0);//坐标从2开始 
} 
