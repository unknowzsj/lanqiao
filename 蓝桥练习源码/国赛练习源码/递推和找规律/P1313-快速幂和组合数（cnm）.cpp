#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int md=10007;
ll res=1;
ll a1,b1,k1,m1,n1;
ll g[10010][10010];
//快速幂 
ll qkpow(ll a,ll b){
	ll ans=1;
	ll base=a;
	while(b>0){
		if(b&1) ans*=base;
		base*=base;
		ans%=md;
		base%=md;
		b>>=1;
	}
	return ans%md;
}
//组合数cnm
ll cnm(ll n, ll m){
	if(m==0) return 0;
	ll mut=1;
	for(ll i=n;i>n-m;--i) mut=(mut*(i%md))%md;
	for(ll i=m;i>1;--i) mut/=i;
	return mut%md;
} 
//杨辉三角求组合数cnm
void yh(){
	g[1][1]=1,g[1][2]=1;
	for(ll i=2;i<=k1;i++){
		for(ll j=1;j<=i+1;j++){
			g[i][j]=(g[i-1][j-1]%md+g[i-1][j]%md)%md;
		}
	}
} 

int main(){
	cin>>a1>>b1>>k1>>n1>>m1;
	yh();//更新组合数 
	res=(g[k1][n1+1]%md)*(qkpow(a1,n1)%md)*(qkpow(b1,m1)%md)%md;
	cout<<res;
	
	return 0;
}
