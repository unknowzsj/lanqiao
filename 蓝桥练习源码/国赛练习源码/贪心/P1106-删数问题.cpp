#include<bits/stdc++.h>
using namespace std;
//贪心：每次删除最大的数--?
//删除第一次遇到n比n+1大的数，按顺序 
string n;
int k;
 
int main(){
	cin>>n>>k;
	int len = n.size();
	for(int i=0;i<k;++i){
		int lc=n.size();//按从小到达排列，删除最后一个 
		for(int j=0;j<len;++j){
			if(n[j]>n[j+1]){
				lc=j;
				break;
			}
		}
		n.erase(lc,1);//指定位置的删除数量 
	}
	//将数字前面的0去除 
	for(int i=0;i<n.size();){
		if(n[i]!='0') break;
		else n.erase(i,1);
	}
	//若删除后n为0，则进行判断并赋值 
	if(n.size()==0) n=n+'0';
	cout<<n<<endl;
	
	return 0; 
} 
