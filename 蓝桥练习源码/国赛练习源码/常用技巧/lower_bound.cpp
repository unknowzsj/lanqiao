#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[5]={1,2,3,4,5};
	cout<<*lower_bound(a,a+5,3,greater<int>());//选出小于等于3的第一个数 
	
	return 0;
} 
