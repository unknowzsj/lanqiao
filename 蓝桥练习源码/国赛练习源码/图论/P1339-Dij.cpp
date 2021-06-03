#include<bits/stdc++.h>
using namespace std;//未通过，不知道原因 
//算法模板结构体 
struct edge{
	int fr,to,dist;
	edge(int u,int v,int d):fr(u),to(v),dist(d) {}
};
int n,m,s,e;
vector<edge> edges;//边的集合 
vector<int> G[100010];//记录每个结点的边在数组位置 
int sta[100010];//储存状态
int dis[100010];//s到i的距离
int p[100010];//最短路径上一条弧 
typedef pair<int,int> pr;
const int inf=100000001; 
//自定义优先队列 
struct node{
	int d,u;
	bool operator < (const node& rhs) const{
		return d>rhs.d;
	}
}; 
//储存边的信息 
void add(int fr,int to,int d){
	edges.push_back(edge(fr,to,d));//将边储存进去
	G[fr].push_back(edges.size()-1);//将点的边的位置进行记录 
}
//Dijkstra算法
void dij(int s){//传入 
	priority_queue<node> que;
	fill(dis,dis+10010,inf);
	dis[s]=0;//起始点距离为0
	//距离在前面，方便判断 
	que.push((node){0,s});//i点到s的距离边储存进去
	while(!que.empty()){
		node x=que.top();que.pop();//读取弹出
		int u=x.u;//读取现在的点
		if(sta[u]) continue;//如果经过了就跳过
		sta[u]=1;
		for(int i=0;i<G[u].size();++i){//读取u点的每段路径的坐标 
			edge& ne=edges[G[u][i]];//读取边的信息
			if(dis[ne.to]>dis[u]+ne.dist){//如果到和u相邻的下一个点的距离比原来的小，就更新数据 
				dis[ne.to]=dis[u]+ne.dist;
				p[ne.to]=G[u][i];//记录这一条弧
				que.push((node){dis[ne.to],ne.to});//将新的结点和距离入队 
			} 
		} 
	} 
} 

int main(){
	cin>>n>>m>>s>>e;
	for(int i=0;i<m;++i){
		int fr,to,dis;
		cin>>fr>>to>>dis;
		add(fr,to,dis);
	} 
	dij(s);//开始遍历 
	cout<<dis[e];
	
	return 0; 
} 
