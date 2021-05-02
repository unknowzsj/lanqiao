#include<bits/stdc++.h>
using namespace std;

vector<int> blog[100000];
//oj没问题，自己测试出现问题，以后再解决	
int main(){
	//条件读取 
	int N,D,K;
	cin>>N>>D>>K;
	int id,t;
	//记录日志 难点 
	for(int i=0;i<N;++i){
		cin>>t;
		cin>>id;
		blog[id].push_back(t);
	}
	//计算每个id的最大点赞数 
	int sum[N];
	int m=0; 	
	for(int i=0;i<100000;++i){
		//个数要大于要求的K 
		if(blog[i].size()>=K){
			int s=0;
			int max=0;
			//排序后进行尺取 
			sort(blog[i].begin(),blog[i].end());
			for(int j=0;j<blog[i].size();++j){
				for(int l=j;l<blog[i].size();++l){
					if(blog[i][j]+10>blog[i][l]) s++;
				}
				if(max<s) max=s; 
			}
			if(max>=K) sum[m++]=i;			
		}
	}
	sort(sum,sum+m);
	for(int i=0;i<m;++i){
		cout<<sum[i]<<endl;
	}
} 
