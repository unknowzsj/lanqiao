#include<bits/stdc++.h>
using namespace std;

//前缀法，可以按字典序排列 
//计算ch在s2中次数 
int k=0;
int compare(string s2,char ch){
	int num=0;
	for(int i=0;i<s2.size();++i){
		if(ch==s2[i]) num++;
	}
	return num;
} 
//前缀遍历 
void allpos(string prefix,string s1,int x,int& k){
	if(prefix.length()==s1.length()){
		k+=1;
		if(k==x){
			cout<<prefix<<endl;
			exit(0);
		} 
	}
	//每次从头扫描字符串 
	for(int i=0;i<s1.size();++i){
		char ch=s1[i];
		//字符可用：在前缀中出现的次数<原字符出现的次数 
		if(compare(prefix,ch)<compare(s1,ch)){
			//添加前缀再次递归 
			allpos(prefix+ch,s1,x,k); 
		}
	}
} 
int main(){
	string str="ABCD";
	string start="A";
	int x=6;
	allpos(start,str,x,k);
	
	return 0;
} 
