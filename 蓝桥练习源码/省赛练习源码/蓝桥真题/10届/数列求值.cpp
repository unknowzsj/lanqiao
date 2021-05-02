#include<iostream>
using namespace std;

typedef long long ll;
ll sum;
ll n;
//动态规划更快 数组空间太大
//用迭代法更好 （节省空间） 
int main(){
	cin>>n;
	int s=0;
	int a=1;
	int b=1;
	int c=1;
	for(ll i=4;i<=n;++i){
		s=(a+b+c)%10000;
		a=b;
		b=c;
		c=s;
	}
	cout<<s<<endl;
}
