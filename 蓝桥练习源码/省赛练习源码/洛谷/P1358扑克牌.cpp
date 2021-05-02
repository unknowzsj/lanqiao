#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
int N,M;
ll md=10007;
int out=1;
//未通过，未找到该解法的问题 
//计算 x中取y个数的取法 
ll cxy(int x,int y){
	ll nx=1;
	ll ny=1;
	if(x>=y){
		for(int i=1;i<=y;++i){
			ny*=i;
			nx*=(x-i+1);
		}
		return  nx/ny;
	}
} 
void dfs(int rid,int nu,int cur,int val[]){
	//没有可取数或者遍历到最后一个选取时 
	if(rid<=1||cur>=M||nu>rid) return;
	ll num1=cxy(rid,nu)%md;
	out=(out*num1)%md;
	//更新，下一个遍历 
	int nres=rid-val[cur];
	int ncur=cur+1;
	int nnu=val[ncur];
	dfs(nres,nnu,ncur,val); 
}
int main(){
	cin>>N>>M;
	int val[M];
	int sum=0;
	for(int i=0;i<M;++i){
		cin>>val[i];
		sum+=val[i]; 
	}
	int xn=val[0];
	if(N>=sum){
		dfs(N,xn,0,val);
	}else out=0;
	cout<<(out+md)%md<<endl;
	
	return 0;
} 
