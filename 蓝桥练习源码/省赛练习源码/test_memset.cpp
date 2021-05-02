#include<bits/stdc++.h>
using namespace std;
//²âÊÔmemset()
int test[10];
int main(){
	memset(test,1,10);
	for(int i=0;i<10;++i){
		cout<<test[i]<<" "; 
	}
	cout<<endl;
	memset(test,1000,10);
	for(int i=0;i<10;++i){
		cout<<test[i]<<" "; 
	}
	cout<<endl;
	fill(test,test+sizeof(test),-1);
	for(int i=0;i<10;++i){
		cout<<test[i]<<" "; 
	}
	cout<<endl;
} 
