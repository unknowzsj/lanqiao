#include<bits/stdc++.h>
using namespace std;
int n,m;
int vis[1001];
int res;

int main(){
	cin>>n>>m;
	int a=sqrt(m+0.5);
	for(int i=2;i<=a;++i){
		if(!vis[i]){//固定素数
			int p=i*i; 
			for(int j=2*p;j<=m;j+=p){//平方的倍数 
				vis[j]=1;
			}
		}
	}
	
	for(int i=n;i<=m;++i){
		if(!vis[i]) res++;
	}
	cout<<res;
	
	return 0;
} 
