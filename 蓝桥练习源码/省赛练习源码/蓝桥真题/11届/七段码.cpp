#include<iostream>
using namespace std;

int main(){
	char ch[]={'a','b','c','d','e','f','g'};
	int n=7;
	int count=0;
	for(int i=(1<<n)-1;i>=1;--i){
		for(int j=n-1;j>=0;--j){
			if(((i>>j)&1)==1) cout<<ch[j];
		}
		count++;
		cout<<endl;
	}
	cout<<count<<endl;
} 
