#include<bits/stdc++.h>
using namespace std;

int n,k;
//计算num的n次 
int power(int num,int n){
	int res=1;
	for(int i=0;i<n;++i){
		res*=num;
	}
	return res;
} 

int main(){
	//处理输入 
	cin>>n;
	int a[n];
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	cin>>k;
	//本题中用不到,输出组合时用 
	vector<vector<int> > res;
	//i为总共由多少种方式
	bool flag=false; 
	for(int i=power(2,n);i>0;--i){
		int sum=0;
		//j为移位的多少，右移 ,从低位到高位 
		for(int j=n-1;j>=0;--j){
			//j是所取的位置 
			if(((i>>j)&1)==1) sum+=a[j]; 
		}
		if(sum==k) flag=true; 
	}
	cout<<(flag ? "yes":"no")<<endl;
	
	return 0; 
} 
