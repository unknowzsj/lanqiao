#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
//未通过，不知道为啥 
//店的信息 
map<int,vector<int> > shop;
int N,M,T;
int main(){
	cin>>N>>M>>T;
	int a[N+1][M+1]={0};//优先级
	bool pro[N+1][M+1]={0};//是否在缓存
	int id,ts;//id--1-N
	int cts=0; 
	//完成输入 
	for(int i=0;i<M;++i){
		cin>>ts>>id;
		shop[id].push_back(ts);
	}
	//确定每个店在每个时刻是否在优先队列中 
	for(int i=1;i<=N;++i){
		int sta[M+1]={0};
		//确定状态 
		for(int j=0;j<shop[i].size();++j){
			//同一时刻的多个订单 
			sta[shop[i][j]]+=1; 
		}
		for(int j=1;j<=M;++j){
			//更新优先级 
			if(sta[j]==0&&a[i][j-1]>0) a[i][j]=a[i][j-1]-1;
			else if(sta[j]>0) a[i][j]=a[i][j-1]+2*sta[j];
			//更新状态 
			if(a[i][j]>=5) pro[i][j]=true;
			else if(pro[i][j-1]==true&&a[i][j]>3) pro[i][j]=true;
			else if(a[i][j]<=3) pro[i][j]=false;
		} 
	}
	//判断店家在T时刻是否在优先队列 
	for(int i=1;i<=N;++i){
		if(pro[i][T]) cts++;
	} 
	cout<<cts<<endl;
	
	return 0; 
}
