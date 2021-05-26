#include<bits/stdc++.h>
using namespace std;
int cts;

bool sushu(int n){
	for(int i=2;i*i<=n;++i){
		if(n%i==0) return false;
	}
	
	return true;
}

int main(){
	cts++;//1µÄÍ³¼Æ 
	for(int i=2;i<=2020;++i){
		if(sushu(i)) cts++;
	}
	cout<<2020-cts;
	
	return 0;
} 
