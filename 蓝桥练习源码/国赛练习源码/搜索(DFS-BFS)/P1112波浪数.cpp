#include<bits/stdc++.h>
using namespace std;
typedef long long ll;//暴力法求不出 
ll jz1,jz2,num1,num2,k;
int cp[10000];
bool wav(ll n,int e){
	int len=1;
	while(n>0){
		cp[len]=n%e;
		n/=e;
		++len;
	}
	//判断是否为波浪数 
	len--;//len会多加一次 
	if(len%2==0){
		for(int i=1;i<=len/2+1;++i){
			if(cp[i]!=cp[i+2]) return false;
		}
	}else{
		for(int j=1;j<=(len+1)/2;++j){
			if(cp[j]!=cp[j+2]) return false;
		}
	}
	return true;
}

int main(){
	cin>>jz1>>jz2>>num1>>num2>>k;
	 
	for(ll i=num1;i<=num2;++i){
		int flag=0;
		for(int j=jz1;j<=jz2;++j){
			if(wav(i,j)) flag++;
		}
		if(flag==k) cout<<i<<endl;
	}
	
	return 0;
}
