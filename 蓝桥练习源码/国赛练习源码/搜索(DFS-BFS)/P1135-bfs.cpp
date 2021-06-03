#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int stp[210];
int sta[210];//需要记录状态,不然找不到会进入死循环 
queue<int> que;
int res;
 
void bfs(int cur){
	if(cur==b){
		cout<<res;
		exit(0);
	} 
	int up=cur+stp[cur];
	int down=cur-stp[cur];
	//加入新的状态 
	if(up>0&&!sta[up]){
		que.push(up);
		sta[up]=1; 
	} 
	if(down>0&&!sta[down]){
		que.push(down);
		sta[down]=1;	
	}
}

int main(){
	cin>>n>>a>>b;
	for(int i=1;i<=n;++i) cin>>stp[i];
	//初始化
	que.push(a);
	sta[a]=1;
	int t=que.size();
	
	while(!que.empty()){
		int now=que.front();
		que.pop();
		//进入循环
		bfs(now);
		t--;//每一组的数量
		if(t==0){
			t=que.size();
			res++;
		} 
	}
	cout<<-1;
	
	return 0; 
}
