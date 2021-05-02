#include<iostream>
using namespace std;
//既约分数
int gcb(int a,int b){
	if(b==0) return a;
	return gcb(b,a%b);
} 
int main(){
	int count=0;
	//规定y>x,所以满足则倒数也满足 
	for(int y=1;y<=2020;++y){
		for(int x=1;x<y;++x){
			if(gcb(y,x)==1) count+=2;//加上倒数 
		}
	}
	//加上1-1的情况 
	cout<<count+1<<endl;
	//2020-2481215 
}
