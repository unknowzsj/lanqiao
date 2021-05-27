#include<bits/stdc++.h>
using namespace std;

//拓展欧几里得，计算线上的点 
void gcdp(int a,int b,int &x,int &y){
	if(b==0){
		x=1;
		y=0;
	}else{
		gcdp(b,a%b,y,x);//x,y位置对调
		y-=x*(a/b); 
	} 
}

int main(){
	int a=12,b=8,c=4;
	int x,y;
	gcdp(a,b,x,y);//这个可以得出ax+by=gcd(a,b)=g(4)的解(x,y),其他解（x+k*b/g,y-k*a/g）-（x0,y0） 
	//ax+by=c,如果c是gcd(a,b)=g的倍数，则一组解为(x*c/g,y*c/g);不为倍数时，无整数解
	//利用上述的其他解就可以不断计算 (x0*c/g,y0*c/g)
	cout<<x<<" "<<y;
	
	return 0;
} 
