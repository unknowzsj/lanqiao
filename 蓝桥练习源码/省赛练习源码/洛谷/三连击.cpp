#include<bits/stdc++.h>
using namespace std;
//初始化 
int main(){
	//最小值就是123，最大333 
	for(int i=123;i<333;++i){
		vector<int> all;
		int d2=i*2;
		int d3=i*3;
		//i分解
		int a1=i%10;//个位
		all.push_back(a1);
		int a2=(i/10)%10;//十位
		all.push_back(a2);
		int a3=i/100;//百位
		all.push_back(a3);
		//d2分解
		int b1=d2%10;//个位
		all.push_back(b1);
		int b2=(d2/10)%10;//十位
		all.push_back(b2);
		int b3=d2/100;//百位
		all.push_back(b3);
		//i分解
		int c1=d3%10;//个位
		all.push_back(c1);
		int c2=(d3/10)%10;//十位
		all.push_back(c2);
		int c3=d3/100;//百位
		all.push_back(c3);
		sort(all.begin(),all.end());
		int cts=0;
		for(int j=1;j<=9;++j){
			if(j==all[j-1]) cts++;
		}
		if(cts==9) cout<<i<<" "<<d2<<" "<<d3<<endl;
	}
} 
