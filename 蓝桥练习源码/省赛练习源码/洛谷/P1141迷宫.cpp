#include<bits/stdc++.h>
using namespace std;
//未通过评测，答案没问题 
//内存限制问题 
int n,m;
struct node{
	int lc;
	int step;
	string mp;
};
queue<node> res;
void bfs(int lc,int stp,string str,int mv[]){
	for(int i=0;i<4;++i){
		int nl=lc+mv[i];
		string nstr=str;
		//越界情况和首尾相连
		if(n==2){//n=2的特殊性 
			if(nl<1||nl>n*n||(nl==3&&lc==2)||(nl==2&&lc==3)) continue;
		} 
		else if(nl<1||nl>n*n||(nl%n==0&&lc%n==1)||(nl%n==1&&lc%n==0)) continue;
		//防止绕圈 
		if(str[lc]!=str[nl]&&str[nl]!='*'){
			nstr[lc]='*'; 
			//更新状态 
			int nstp=stp+1;
			node nd;
			nd.lc=nl;
			nd.mp=nstr;
			nd.step=nstp;
			res.push(nd);
		}
	}
}

int main(){
	cin>>n>>m;
	pair<int,int> loc[m];
	string mps="s";
	//右左下上 
	int mv[4]={1,-1,n,-n};
	//储存地图 
	for(int i=0;i<n;++i){
		string ch;
		cin>>ch;
		mps+=ch;
	}//储存坐标 
	for(int i=0;i<m;++i){
		cin>>loc[i].first>>loc[i].second;
	}
	
	//开始遍历
	for(int i=0;i<m;++i){
		//queue<node> res;
		int mx=0; 
		//初始化,最初的状态开始 
		int x=loc[i].first;
		int y=loc[i].second;
		node start;
		start.mp=mps;
		start.lc=x*(y-1)+y; 
		start.step=1;
		res.push(start);
		//开始遍历 
		int t=res.size();
		while(!res.empty()){
			node nnde=res.front();
			int nlc=nnde.lc;
			int nsp=nnde.step;
			string nmp=nnde.mp;
			res.pop();
			//找到最大步数 
			if(mx<nsp) mx=nsp;
			 
			bfs(nlc,nsp,nmp,mv);
			t--;
			if(t==0){
				//更新下一步 
				t=res.size();
			}
		} 
		cout<<mx<<endl;
	} 
}
