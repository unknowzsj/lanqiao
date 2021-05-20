#include<bits/stdc++.h>
using namespace std;
set<int> res;
int a,b,c;//最大容量 
int na,nb,nc;//现在容量 
bool bol[21][21][21];//判重
 
void dfs(int a1,int b1,int c1){
	//退出循环 
	if(bol[a1][b1][c1]) return;
	bol[a1][b1][c1]=true;
	if(a1==0) res.insert(c1);
	//模拟六种倾倒方式 
	if(a1){//a1有奶 
		if(b1<b){//b1未满,a1->b1 
			if(b-b1>=a1) dfs(0,b1+a1,c1);//a1不够 
			else dfs(a1+b1-b,b,c1);
		}
		if(c1<c){//c1未满,a1->c1 
			if(c-c1>=a1) dfs(0,b1,c1+a1);//a1不够 
			else dfs(a1+c1-c,b1,c);
		}
	} 
	if(b1){//b1有奶 
		if(a1<a){//a1未满,b1->a1 
			if(a-a1>=b1) dfs(a1+b1,0,c1);//b1不够 
			else dfs(a,b1+a1-a,c1);
		}
		if(c1<c){//c1未满,b1->c1 
			if(c-c1>=b1) dfs(a1,0,c1+b1);//b1不够 
			else dfs(a1,b1+c1-c,c);
		}
	}
	if(c1){//c1有奶 
		if(a1<a){//a1未满,c1->a1 
			if(a-a1>=c1) dfs(a1+c1,b1,0);//c1不够 
			else dfs(a,b1,c1+a1-a);
		}
		if(b1<b){//b1未满,c1->b1 
			if(b-b1>=c1) dfs(a1,b1+c1,0);//c1不够 
			else dfs(a1,b,c1+b1-b);
		}
	}	
} 
int main(){
	cin>>a>>b>>c;
	//初始化
	nc=c;
	dfs(na,nb,nc); 
	
	//输出
	for(set<int>::iterator i=res.begin();i!=res.end();++i){
		cout<<*i<<" ";
	} 
	return 0;
}
