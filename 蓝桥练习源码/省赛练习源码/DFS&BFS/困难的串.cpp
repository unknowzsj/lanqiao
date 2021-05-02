#include<iostream>
#include<algorithm>
#include<string> 
using namespace std;
//第n个，用l个字母进行 
int n,l;
//储存结果的向量集 
string res="";

bool check(char ch){
	int count=1;
	//substr(pos,len)在位置pos开始截取len个字符
	//-2是因为每次s1，s2均要退一步 
	for(int i=res.size()-1;i>=0;i-=2){
		string s1=res.substr(i,count);
		//s2拷贝从i+count到末尾的几个字符 
		string s2=res.substr(i+count)+ch;
		if(s1==s2) return false;
		count++;
	}
	return true;
} 
void dfs(int cur){
	//达到n就退出 
	if(cur==n){
		cout<<res<<endl;
		exit(0);
	}
	//进行深度搜索	
	for(char i='A';i<'A'+l;++i){
		//前面已经排好，只需要判断 
		if(check(i)){
			res.push_back(i);
			cur++;
			dfs(cur);
			res.erase(res.end()-1);//回溯 
		} 
	} 
}

int main(){
	cin>>n>>l;
	int cur=0;
	dfs(cur);
	
	return 0;
} 
