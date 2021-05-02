#include<bits/stdc++.h>
using namespace std;
//数据太大，超时 
//数学方法可以过 
int N;
int yueshu(int n){
	int cts=0;
	for(int i=1;i*i<=n;++i){
		if(n%i==0) cts+=2;
		//平方只取一个 
		if(i*i==n) cts--; 
	}
	return cts;
} 
int main(){
	cin>>N;
	int sum=0;
	for(int i=1;i<=N;++i){
		sum+=yueshu(i);
	} 
	cout<<sum<<endl;
	
	return 0;
}
