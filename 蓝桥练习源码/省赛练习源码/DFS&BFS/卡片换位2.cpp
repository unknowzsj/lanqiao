#include<bits/stdc++.h>
using namespace std;
//题目规定了2*3 
//记录a,b初始位置 
int ax,bx;
string s1,s2;
struct node{
	string alls;
	int step;
};
queue<node> state;
//移动方式 
int mo[4]={-1,1,-3,3};
//防止走重复的路
map<string,bool> con; 
 
void bfs(node sno){
	//找到空格的位置 
	int spa;
	for(int i=0;i<6;++i){
		if(sno.alls[i]==' ') spa=i; 
	}
	//遍历比较 
	for(int i=0;i<4;++i){
		int newx=spa+mo[i];
		//越界 ,别忘了首尾相接的情况 
		if(newx<0 || newx>5 || (spa==2&&newx==3) ||(spa==3&&newx==2)) continue;
		//新的结点入队列 
		node ns=sno;
		ns.alls[spa]=ns.alls[newx];
		ns.alls[newx]=' ';
		if(!con[ns.alls]){
			con[ns.alls]=true;
			ns.step++;
			state.push(ns);
		}
	} 
}

int main(){
	//初始化,有空格，用cin会识别空格 
	getline(cin,s1);
	getline(cin,s2); 
	string start=s1+s2;
	//记录初始位置 
	for(int i=0;i<6;++i){
		if(start[i]=='A') ax=i;
		if(start[i]=='B') bx=i;
	}
	//初始化输入结点 
	node stnode;
	stnode.alls=start;
	stnode.step=0; 
	state.push(stnode);
	//记录现在的A，B位置 
	int nax,nbx; 
	int t=state.size();
	while(!state.empty()){
		node frn=state.front();
		for(int i=0;i<6;++i){
			if(frn.alls[i]=='A') nax=i;
			if(frn.alls[i]=='B') nbx=i;	
		}
		state.pop();
		//判断是否相等 
		if(nax==bx && nbx==ax){
			cout<<frn.step<<endl;
			break; 
		} 
		//下一个遍历 
		bfs(frn);
		t--;
		if(t==0){
			t=state.size();
		}	
	} 
}
