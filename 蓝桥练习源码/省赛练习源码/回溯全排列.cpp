#include<bits/stdc++.h>
using namespace std;

vector<string> res;
//全排列的函数 
//k是当前所在的位置 
vector<string> allpos(string s,int k){
	if(k==s.size()){
		res.push_back(s);
	} 
	for(int i=k;i<s.size();++i){
		swap(s[k],s[i]);//交换位置 
		allpos(s,k+1);//下一个位置 
		swap(s[k],s[i]);//回溯 
	}
	return res;
}
int main(){
	string str="ABCD";
	vector<string> outres=allpos(str,0);
	for(int i=0;i<outres.size();++i){
		cout<<outres[i]<<endl;	
	}
	return 0;
} 
