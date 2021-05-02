#include<bits/stdc++.h>
using namespace std;
//DP题，用dfs超时
//不知道为什么减钱通过，加钱不通过(用错变量) 
int N,M;
int money[100001];
int kin;
void dfs(int cur,int sum){
	//钱数刚好就种类+1 
	if(sum==M){
		kin++;
		return; 
	}//没有菜,超出钱数，结束 
	if(cur==N||sum>M) return;
	//不选cur
	int cur1=cur+1;
	dfs(cur1,sum);
	//选cur
	int cur2=cur+1;
	int sum2=sum+money[cur];
	dfs(cur2,sum2); 
}
int main(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		cin>>money[i];
	}
	dfs(0,0);//0元，0菜
	cout<<kin<<endl;
	
	return 0; 
} 
