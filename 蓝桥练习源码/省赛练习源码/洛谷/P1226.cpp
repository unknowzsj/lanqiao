#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b,p,k;
int main(){
	cin>>b>>p>>k;
	ll ans=1;
	ll base=b;
	ll pt=p;
	while(pt>0){
		if(pt&1){
			ans=(ans*base)%k;
		}
		base=(base*base)%k;
		pt>>=1;
	}
	cout<<b<<"^"<<p<<" mod "<<k<<"="<<ans%k<<endl;
	
	return 0;
}
