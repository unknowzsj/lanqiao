#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res;
int flag[70];//取第一次碰到的 

int yus(ll n){
	int cts=0;
	for(ll i=1;i*i<=n;++i){
		if(n%i==0) cts+=2;//双倍 
		if(i*i==n) cts--;//重复-1 
	}
	return cts; 
}

int main(){
	int len=1;
	int su;
	for(ll i=1;i<=100000000;++i){
		su=yus(i);
		if(su==len&&flag[len]==0){//没有取过 
			flag[len]==1;
			//cout<<i<<endl; 
			res+=i;
			if(len==60){
				cout<<i<<"  "<<yus(i);
				break;//等于60个退出 
			}
			len++;
		}
	}
	cout<<res;
	
	return 0;
} 
