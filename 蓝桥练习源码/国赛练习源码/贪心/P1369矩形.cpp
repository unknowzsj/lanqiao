#include<bits/stdc++.h>//未完成，值得琢磨 
using namespace std;//贪心思路：选出长和宽中找到的最多点，消除点后选出另一个的最多点，就是答案  
int n;
struct Node{
	int nx,ny;
}node[310]; 
int allx[110],ally[110];
int res;
//sort(allx,allx+110,greater<int>());从大到小 

int main(){
	cin>>n;
	for(int i=0;i<n;++i){//数据的输入 
		int x,y;
		cin>>x>>y;
		node[i].nx=x;
		node[i].ny=y;
		++allx[x];
		++ally[y];
	}
	//寻找最长的2个长和2个宽，从而确定哪个固定
	int ml1,ml2,mw1,mw2=0;
	int ll1,ll2,lw1,lw2; 
	for(int i=0;i<100;++i){
		if(allx[i]>ml1){
			ml1=allx[i];
			ml2=ml1;
			ll1
		}
	} 
	
	return 0; 
}
