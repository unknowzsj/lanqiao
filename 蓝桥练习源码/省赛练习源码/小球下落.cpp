#include<bits/stdc++.h>
using namespace std;

const int maxd=20;
int s[1<<maxd];
int main(){
	int D,I;
	while(scanf("%d%d",&D,&I)==2){
		memset(s,0,sizeof(s));
		int k,n=(1<<D)-1;
		for(int i=0;i<I;++i){
			k=1;
			for(;;){
				s[k]=!s[k];
				//开关转换后，s[k]==1--k*2;s[k]==0--k*2+1
				k = s[k]? k*2:k*2+1;
				if(k>n) break;
			}
		}
		printf("%d\n",k/2);
	}
} 
