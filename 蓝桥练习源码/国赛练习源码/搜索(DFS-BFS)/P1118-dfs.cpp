#include<bits/stdc++.h>
using namespace std;
int n,sum;
int num[15];
int res[15][15];//可以覆盖路径，无需二维数组 

bool check(int beg){//检查是否合格 
	int k=n;
	int chk[15]={0};
	for(int i=1;i<=n;++i){
		chk[i]=res[beg][i];
	}
	while(k>1){
		for(int i=1;i<k;++i){
			chk[i]=chk[i]+chk[i+1];
		}
		k--;
	}
	if(chk[1]==sum) return true;
	else return false;
}
bool yhsj(int beg){
	
} 
void dfs(int sta,int cts){//全排列 
	if(cts==n+1){
		if(check(sta)){
			for(int i=1;i<=n;++i){
				cout<<res[sta][i]<<" ";
			}
			exit(0);//输出最小，直接退出 
		}
	}
	for(int i=1;i<=n;++i){
		if(!num[i]){
			num[i]=1;//选过的标记
			res[sta][cts]=i;//路径记录 
			dfs(sta,cts+1);
			num[i]=0; 
		}
	}
}

int main(){
	cin>>n>>sum;
	for(int i=1;i<=n;++i){
		num[i]=1;//遍历第一个是几
		res[i][1]=i;//路径记录
		dfs(i,2);
		num[i]=0;//回溯 
	}
	
	return 0;
} 
