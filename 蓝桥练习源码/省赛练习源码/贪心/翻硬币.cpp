#include<bits/stdc++.h>
using namespace std;

int main(){
	//两个一次操作，相差的不会出现奇数面的情况
	string s1,s2;
	cin>>s1;
	cin>>s2;
	
	int n=s1.size();
	int diff[n];
	int j=0,sum=0,x;
	//计算相差的位置 
	for(int i=0;i<n;++i){
		if(s1[i]!=s2[i]) diff[j++]=i;
	}
	sort(diff,diff+j);
	//排序后选择最近的进行相减 
	for(int i=0;i<j;i+=2){
		x=diff[i+1]-diff[i];
		sum+=x;
	}
	cout<<sum<<endl;
} 
