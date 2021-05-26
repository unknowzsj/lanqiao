#include<bits/stdc++.h>
using namespace std;
int cts;
int pn=12*10+31+28; 

bool twoin(int n){//判断是否又2 
	while(n){
		if((n%10)==2) return true;
		n/=10;
	}
	return false;
}
bool run(int y){//判断是否为闰年 
	if((y%100)==0){
		if(y%400==0) return true;
	}else{
		if(y%4==0) return true;
	} 
	return false;
}

int main(){
	for(int i=1900;i<=9999;++i){
		if(run(i)) cts++;//闰年加29这天 
		//年中有2，则加366 
		if(twoin(i)) cts+=366;
		else cts+=pn;//无2，则加平年的带2数 
	}
	cout<<cts;
	
	return 0; 
}
