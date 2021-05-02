#include<bits/stdc++.h>
using namespace std;

int n,m,k;
//不要用小写，与map函数重复 
char Map[1001][1001];
//x,y的变化，上下左右 
int cha[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
//队列进行广度遍历 
queue<pair<int,int> > grass;
//长草的函数 
void grow(int x,int y){
	for(int i=0;i<4;++i){
		//更新坐标 
		int nx=x+cha[i][0];
		int ny=y+cha[i][1];
		//边界限制,继续下一个坐标 
		if(nx<1 || ny<1 || nx>n || ny>m) continue;
		//进行长草 
		if(Map[nx][ny]!='g'){
			Map[nx][ny]='g';
			grass.push(pair<int,int>(nx,ny)); 
		}
	}
}

int main(){
	cin>>n>>m;
	//读取地图信息 
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>Map[i][j];
			//将首批满足条件的坐标点入队列 
			if(Map[i][j]=='g'){
				grass.push(pair<int,int>(i,j)); 	
			}
		}
	} 
	//读取月数 
	cin>>k;
	//遍历的个数 
	int t=grass.size();
	//队列不为空和月数为满足，不断循环 
	while(!grass.empty() && k>0){
		//读取第一个入队的组合的x，y 
		int fx=grass.front().first;
		int fy=grass.front().second;
		grass.pop();//出队
		grow(fx,fy);
		//长了一次需要减去一个结点 
		t--;
		//一次遍历结束，更新新的点和月数 
		if(t==0){
			t=grass.size();
			k--; 
		} 
	}
	//输出地图更新的信息 
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cout<<Map[i][j];
		}
		cout<<endl;
	}
	
	return 0;
} 
