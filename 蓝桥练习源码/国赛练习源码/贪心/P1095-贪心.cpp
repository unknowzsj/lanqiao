#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,s,t,dis,tim; 

int main(){
	cin>>m>>s>>t;
	ll d1,d2=0;//记录闪现和走路的方式
	for(int i=1;i<=t;++i){
		//闪现法 
		if(m>=10){
			d1+=60;//魔法够 
			m-=10; 
		}
		else m+=4;
		//步行
		d2+=17;
		if(d1>d2) d2=d1;//步行快,进行替换
		//判断输出
		if(d2>=s){
			cout<<"Yes"<<endl<<i;
			return 0;
		} 
	} 
	cout<<"No"<<endl<<d2;
	
	return 0; 
}
