#include<bits/stdc++.h>
using namespace std;
int n,res;
int mp[110][110];
int pre[110][110];

int main(){
	cin>>n;
	for(int i=0;i<n;++i){
		int x,y;
		cin>>x>>y;
		mp[x][y]=1;
	}
	//计算前缀和
	for(int i=1;i<110;++i){
		for(int j=1;j<110;++j){
			pre[i][j]=pre[i-1][j]+pre[i][j-1]+mp[i][j]-pre[i-1][j-1];
		}
	} 
	//计算边覆盖的最大值
	for(int i=1;i<110;++i){
		for(int j=1;j<110;++j){
			int su;
			su=pre[i][j]+pre[1][j-1]+pre[i-1][1]-pre[i-1][j-1];
			res=max(su,res);
		}
	} 
	cout<<res;
	
	return 0;
} 
