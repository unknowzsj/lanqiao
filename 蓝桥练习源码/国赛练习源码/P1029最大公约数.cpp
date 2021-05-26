#include<bits/stdc++.h>
using namespace std;

int cts=0;
int x,y;
//最大公约数 
int gcb(int a,int b){
	if(b==0) return a;
	return gcb(b,a%b);
}

int main(){
	cin>>x>>y;
	//最大公约数 
	int a=gcb(x,y);
	//最小公倍数是x*y/a,两数相乘除以最大公约数
	//暴力求解大一点，防止大输入出错 
	int b=x*y/a;
	for(int i=2;i<1000000;++i){
		int p=i;
		if(x*y%p==0){
			int q=x*y/p;
			if(gcb(p,q)==x&&p*q/x==y) cts++;
		}
	}
	cout<<cts<<endl;
	
	return 0;
} 
