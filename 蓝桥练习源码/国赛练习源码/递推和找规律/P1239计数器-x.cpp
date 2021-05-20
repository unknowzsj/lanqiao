#include<bits/stdc++.h>//未完成0的计算出现问题 
using namespace std;
typedef long long ll;
int res[10];//记录每个数字的个数 
int num[10];//记录分解的数字 
int N;//输入的数
//快速幂(a的b次)
ll quick(ll a,ll b){
	ll ans=1,base=a;
	while(b>0){
		if(b&1) ans*=base;
		base*=base;
		b>>=1;
	}
	return ans;
} 
 
int main(){
	cin>>N;
	
	int len=0;//记录数字长度 
	while(N){//分解数字 
		num[len]=N%10;
		N/=10;
		len++;
	}
	//计算个数 
	for(int j=0;j<=9;++j){//依次计算0-9 
		for(int i=0;i<len;++i){//放在不同的位置 
			if(j==0&&i==len-1) continue;//如果0位于最高位，跳过
			 
			int sum=0;
			int mup=1;
			//计算前几位相乘 
			for(int k=i+1;k<len;++k){
				mup*=(num[k]+1);//前几位相乘 
			}
			//计算后几位的总数 
			for(int l=0;l<i;++l){
				sum+=num[l]*quick(10,l); 
			}
			//j==0单独计算 
			if(j==0){
				 res[j]+=(sum+1)*(mup-1); 
			} 
			else if(j<=num[i]) res[j]+=(sum+1)*mup; 
			else res[j]+=(sum+1)*(mup-1); 
		}
	}
	
	for(int i=0;i<=9;++i) cout<<res[i]<<endl;
	
	return 0;
}
