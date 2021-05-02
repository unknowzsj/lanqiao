#include<bits/stdc++.h>
using namespace std;

int N;
int L,R;
int cts=0;
int main(){
	cin>>N;
	int a[N];
	int sum=0;
	for(int i=0;i<N;++i){
		cin>>a[i];
		sum+=a[i];
	} 
	cin>>L>>R;
	int sml=0;
	int big=0;
	for(int i=0;i<N;++i){
		if(a[i]<L) sml+=(L-a[i]);
		else if(a[i]>R) big+=(a[i]-R);
	} 
	cts=(sml>big? sml:big);
	//不满足情况，最后进行不满足的判断
	//能用乘法就少用除法 
	if(sum<L*N||sum>R*N) cts=-1;
	cout<<cts<<endl;
	
	return 0; 
} 
