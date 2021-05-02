#include<iostream>
#include<algorithm>
using namespace std;

bool check(int test){
	//判断test的是否为素数 
	for(int i=2;i<test;++i){
		if(test%i==0) return false;
	}
	//否则检测成功 
	return true;
}
int main(){
	int n=check(7);
	cout<<n<<endl;
}
