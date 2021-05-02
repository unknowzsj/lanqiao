#include<iostream>
using namespace std;

bool check(int num){
	if(num==2||num==0||num==1||num==9) return true;
	else return false;
}
int main(){
	long long sum=0;
	for(int i=1;i<=2019;++i){
		if(i<10){
			if(check(i)) sum+=i*i;
		}else if(i<100){
			int a=i%10;//个位 
			int b=i/10;//十位
			if(check(a)||check(b)){
				sum+=i*i;
			} 
		}else if(i<1000){
			int a=i%10;//个位
			int b=(i/100);//百位
			int c=(i/10)%10;//十位
			if(check(a)||check(b)||check(c)){
				sum+=i*i;
			}
		}else if(i<10000){
			int a=i%10;//个位 
			int b=i/1000;//千位
			int c=(i/10)%10;//十位
			int d=(i/100)%10;//百位
			if(check(a)||check(b)||check(c)||check(d)){
				sum+=i*i;
			} 
		}
	}
	cout<<sum<<endl;
	
	return 0;
} 
