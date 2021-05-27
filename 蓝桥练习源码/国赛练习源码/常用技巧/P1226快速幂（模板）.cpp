#include<bits/stdc++.h>
using namespace std;

typedef long long ll; 
ll b,p,k;
//ÇóaµÄb´Î 
ll quickpower(ll a,ll b){
	ll ans=1;
	ll base=a;
	while(b>0){
		if(b&1) ans*=base;
		base*=base;
		b>>=1;
	}
	return ans; 
}
int main(){
	cin>>b>>p>>k;
	ll out=quickpower(b,p);
	out%=k;
	cout<<b<<"^"<<p<<" mod "<<k<<"="<<out<<endl;
	
	return 0;
}
