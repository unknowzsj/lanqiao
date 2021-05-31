#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
string str;
ll md=9944353;

ll qkpow(ll a,ll b){
	ll base=a;
	ll ans=1;
	while(b){
		if(b&1) ans=(ans*base)%md;
		base=(base*base)%md;
		b>>=1;
	}
	return ans%md;
}
int main(){
	cin>>str; 
	cout<<qkpow(26,str.size());
	
	return 0;
}
