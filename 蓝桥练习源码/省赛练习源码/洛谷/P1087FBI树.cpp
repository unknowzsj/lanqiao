#include<bits/stdc++.h>
using namespace std;

int n;
string bck=""; 
string str;
//判定是哪种类型 
char check(string s){
	int cts=0;
	for(int i=0;i<s.size();++i){
		if(s[i]=='1') cts++;
	} 
	if(cts==0) return 'B';
	else if(cts==s.size()) return 'I';
	else return 'F';
} 
void dfs(string s){
	//结束 
	if(s.size()==1){
		char ch=check(s);
		bck+=ch;
		return;
	}
	char ch2=check(s);
	bck+=ch2;
	//先加再遍历,顺序根右左
	string right=s.substr(s.size()/2,s.size()/2);
	string left=s.substr(0,s.size()/2);
	//先右
	dfs(right);
	//再左
	dfs(left); 
} 
int main(){
	cin>>n;
	cin>>str;
	dfs(str);
	string out="";
	for(int i=bck.size()-1;i>=0;--i){
		out+=bck[i];
	}
	cout<<out<<endl;
	
	return 0; 
}
