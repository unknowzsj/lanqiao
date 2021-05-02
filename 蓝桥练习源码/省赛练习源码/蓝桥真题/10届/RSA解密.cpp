#include<iostream>
using namespace std;

typedef long long ll;
//质数判断 
bool zhishu(ll n){
	for(ll i=2;i*i<n;++i){
		if(n%i==0) return false;
	}
	return true;
}
//最大公因数,互质判断 
ll gcb(ll a,ll b){
	if(b==0) return a;
	else return gcb(b,a%b);
}

int main(){
	ll n=1001733993063167141;
	ll d=212353;
	ll C=20190324;
	ll e; 
	
	for(ll i=2;i*i<=n;++i){
		//得到p,q; 
		if(n%i==0){
			ll j=n/i;
			//p,q为质数 
			if(zhishu(i)||zhishu(j)){
				ll p=i;
				ll q=j;
				cout<<p<<" "<<q<<endl;
				//判断互质 
				if(gcb(d,p-1)==1&&gcb(d,q-1)==1){
					ll m=p-1;
					ll n=q-1;
					//求e 
					for(ll k=1;k<n;++k){
						ll sum=m*n*k+1;
						if(sum>0&&sum%d==0){
							e=sum/d;
							cout<<e<<endl;
							break;
						}
					}
				}
			}
		} 
	}
	ll sc=1;
	for(ll i=1;i<=e;++i){
		sc=(sc*C)%n;
	}
	cout<<sc<<endl; 
} 
