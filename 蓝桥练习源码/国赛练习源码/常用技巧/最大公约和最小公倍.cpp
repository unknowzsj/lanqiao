#include<bits/stdc++.h>
using namespace std;

int gcb(int a,int b){
	return b==0?a:gcb(b,a%b);
} 

int main(){
	int x=12,y=8;
	cout<<"最大公约数"<<gcb(x,y)<<endl;
	cout<<"最小公倍数"<<(x/gcb(x,y))*y;//x*y/gcb(x,y),两数相乘除以最大公约数就是最小公倍数
	
	return 0; 
}
