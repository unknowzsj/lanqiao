#include<bits/stdc++.h>
using namespace std;
#define inf 1e9;//定义最大值 
const int maxn=2505;
vector<pair<int,int> > edge[maxn];//记录结点的连接结点和距离 
int dis[maxn];//记录距离 
//自定义优先队列 
struct node{
	int d,u;
	bool operator < (const node& rhs) const{
		return d>rhs.d;
	}
};

void dijkstra(int s){	
	priority_queue<node> que;//大根堆,利用自定义
	dis[s]=0;
	que.push((node){dis[0],s});//将初始点存入 
	while(!que.empty()){
		int now=que.top().u;//取出该点 
		que.pop();
		for(int i=0;i<edge[now].size();i++) {//遍历now的所有边 
			int v=edge[now][i].first;//取连接的点 
			if(dis[v]>dis[now]+edge[now][i].second) {//松弛
				dis[v]=dis[now]+edge[now][i].second;
				que.push((node){dis[v],v});//将新的结点入队 
			}
		}
	}
}
int main() {
	int n,m,s,e;
	cin>>n>>m>>s>>e;
	for(int i=0;i<maxn;i++) edge[i].clear(),dis[i]=inf;//清空队列，将距离设为最大 
	for(int i=1;i<=m;i++) {//建图
		int u,v,d;
		cin>>u>>v>>d;
		edge[u].push_back(make_pair(v,d));
		edge[v].push_back(make_pair(u,d));
	}
	dijkstra(s);
	cout<<dis[e];
	return 0;
}
