#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll jz1,jz2,num1,num2,k;
ll wn[10000010];//储存重数

void chong(){
	for(int jz=jz1;jz<=jz2;++jz){
		for(int i=1;i<jz;++i){//第一位,不能为0 
			for(int j=0;j<jz;++j){
				if(i!=j){//两个位置不相等 
					int x=0,len=0;//x为构造的数，len为数字长度 
					while(x<=num2){
						if(len%2==0){
							x=x*jz+i;//计算成十进制,每加一位就是所有的乘以进制 
							++len;
						}else{
							x=x*jz+j;
							++len; 
						}
						if(x>=num1&&x<=num2) ++wn[x];//此数是该进制的波浪数 
					}
				}
			} 
		}
	}
}

int main(){
	cin>>jz1>>jz2>>num1>>num2>>k;
	chong();//构造重数 
	for(int i=num1;i<=num2;++i){
		if(wn[i]==k) cout<<i<<endl;
	}
	
	return 0;
} 
