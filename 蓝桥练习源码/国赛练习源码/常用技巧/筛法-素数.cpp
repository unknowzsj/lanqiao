#include<bits/stdc++.h>
using namespace std;
int vis[10010];

int main(){
	//普通版 
	for(int i=2;i<=10010;++i){//从2开始，1，2均为素数 
		for(int j=2*i;j<=10010;j+=i){//将每个数的倍数设为1，剩下的就是素数 
			vis[j]=1; 
		}
	}
	//升级版
	int m=sqrt(n+0.5);
	for(int i=2;i<=m;++i){
		if(!vis[i]){//限定为奇数，偶数的在i=2时都填满了 
			for(int j=i*i;i<=n;j+=i){//j=i*i,其他的都被i=2时的删掉了 
				vis[j]=1;
			}
		}
	} 
	
	cout<<vis[37];//素数 
	
	return 0;
} 
