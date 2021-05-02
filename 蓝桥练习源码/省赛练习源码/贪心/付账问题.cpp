#include<bits/stdc++.h>
using namespace std;
typedef long long ll;//这个很重要 

int main(){
  ll n;//测试时如果时int会越界 
  double s;
	cin>>n>>s;
	int moy[n];
	double avg=s*1.0/n;
	double ans=0;
	//获取钱数 
	for(int i=0;i<n;++i){
		cin>>moy[i];
	}
	//排序，前面符合则后面符合 
	sort(moy,moy+n);
	//减去平均的剩余钱 
	for(int i=0;i<n;++i){
		//小于平均数 
		if(moy[i]*(n-i)<s){
			ans+=(moy[i]-avg)*(moy[i]-avg);
			s-=moy[i];
		}else{//反之则大于平均数，将剩下的进行平均 
			double cur=s*1.0/(n-i); 
			ans+=(cur-avg)*(cur-avg)*(n-i);
			break; 
		}
	}
	printf("%.4lf",sqrt(ans/n));
	
	return 0;
}


