#include<bits/stdc++.h>
using namespace std;

int N;
//最大公约数，数论 
int gcb(int a,int b){
	if(b==0) return a;
	return gcb(b,a%b); 
} 
int main(){
	cin>>N;
	int nums[N];
	int big,small; 
	double min=INT_MAX;
	int up,down; 
	//读取数据 
	for(int i=0;i<N;++i){
		cin>>nums[i];
	}
	sort(nums,nums+N);
	/*错误点：未考虑公比的2次和3次最大公比时1次，而不是2次 
	//计算最小公比,i<N-1,防止越界 
	for(int i=0;i<N-1;++i){
		double 	dvi=nums[i+1]/nums[i];
		if(min>dvi){
			big=nums[i+1];
			small=nums[i];
		}
	}
	//输出分数,分子和分母除以最大公约数 
	int tge=gcb(big,small);
	cout<<big/tge<<"/"<<small/tge<<endl;
	*/
	
} 
