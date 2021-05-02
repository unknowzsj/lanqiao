#include<bits/stdc++.h>
using namespace std;
/*
	第一行：输入为基础数列的个数，和要求的等差
	第二行：具体数列
	要求：形成等差数列最少需要变化几个数 
*/
int n,k; 
int main(){
	cin>>n>>k;
	int num[n];
	//cin见到空格和回车结束一次读取 
	for(int i=0;i<n;++i){
		cin>>num[i];
	}
	//暴力 
	int min=n+1;//选择i不变 
	for(int i=0;i<n;++i){
		int count;
		for(int j=0;j<i;++j){
			if(num[i]-num[j]!=k) count++;
		}
		for(int j=i;j<n;++j){
			if(num[j]-num[i]!=k) count++;
		}
		if(min>count) min=count;
	}
	cout<<min<<endl;
	
	return 0;
} 
