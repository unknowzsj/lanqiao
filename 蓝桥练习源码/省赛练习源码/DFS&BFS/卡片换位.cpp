#include<bits/stdc++.h>
using namespace std;
//底层库出现问题 
struct node{
	char con[2][3];
};
//不走重复和无意义的路 
map<node,bool> sta;
//定义标志位，关羽和张飞的位置
map<char,pair<int,int> > loc;
//遍历状态
queue<node> now;
int move[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
void bfs(node nown){
	//找到空格位 
	int spx,spy;
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			if(nown.con[i][j]==' '){
				spx=i;
				spy=j;
			}
		}
	}
	//遍历位置 
	for(int i=0;i<4;++i){
		int nx=spx+move[i][0];
		int ny=spy+move[i][1];
		//越界跳出 
		if(nx<0 || nx>=2 || ny<0 || nx>=3) continue;
		node nnow = nown;
		nnow.con[spx][spy]=nnow.con[nx][nx];
		nnow.con[nx][ny]=' ';
		if(!sta[nnow]){
			sta[nnow]=true;
			now.push(nnow);
		} 
	}
}

int main(){
	//初始化 
	node start;
	for(int i=0;i<2;++i){
		for(int j=0;j<3;++j){
			cin>>start.con[i][j];
			if(start.con[i][j]=='A'){
				loc['A'].first=i;
				loc['A'].second=j;
			}
			if(start.con[i][j]=='B'){
				loc['B'].first=i;
				loc['B'].second=j;
			}
		}
	}
	now.push(start);
	
	int num=0;
	int t=now.size();
	pair<int,int> a,b;
	while(!now.empty()){
		//找出状态的A，B位置 
		node frn=now.front();
		for(int i=0;i<2;++i){
			for(int j=0;j<3;++j){
				if(frn.con[i][j]=='A'){
					a.first=i;
					a.second=j;	
				};
				if(frn.con[i][j]=='B'){
					b.first=i;
					b.second=j;
				}
			}
		}
		now.pop();
		//进行替换比较 
		if(a==loc['B'] && b==loc['A']){
			cout<<num<<endl;
			break;
		}
		//遍历
		bfs(frn); 
		t--;
		if(t==0){
			t=now.size();
			num++; 
		}
	} 
}
