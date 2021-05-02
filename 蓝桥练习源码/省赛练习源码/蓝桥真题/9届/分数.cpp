#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll mi(int a,int b){
	ll base=a;
	ll ans=1;
	while(b>0){
		if(b&1) ans*=base;
		base*=base;
		b=b>>1;
	}
	return ans;	
}
int main(){
	//cin>>N;
	ll res=mi(2,20);
	ll res2=mi(2,19);
	cout<<(res-1)<<"/"<<res2;
	
	return 0;
}
