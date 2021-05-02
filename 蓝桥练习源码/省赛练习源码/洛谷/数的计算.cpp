#include<bits/stdc++.h>
using namespace std;
int cts=1; 
int num(int n){
	for(int i=1;i<=n/2;++i){
		cts++;
		num(i);
	}
	return cts;
} 

int main(){
	int n;
	cin>>n;
	int res=num(n);
	cout<<res<<endl;
	
	return 0;
}

