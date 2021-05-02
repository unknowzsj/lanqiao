#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll Max=59084709587505;
//set-排序且不重复 
int main(){
	int a[]={3,5,7};
	ll t=1;//开始的数
	set<ll> res; 
	while(1){
		for(int i=0;i<3;++i){
			ll tt=t*a[i];
			if(tt<=Max) res.insert(tt);//只收取比最大值小的数 
		}
		t=(*res.upper_bound(t));//比t大的最小数，lower_bound-大于等于t的最小数 
		if(t>=Max) break;
	}
	cout<<res.size()<<endl;
	
	return 0;
} 
