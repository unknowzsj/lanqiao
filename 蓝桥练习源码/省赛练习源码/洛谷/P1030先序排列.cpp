#include<bits/stdc++.h>
using namespace std;

string md,bk;
//string fn="";
//find()可以直接找到字符的下标 
void dfs(string md,string bk){
	if(bk.size()>0){
		char rt=bk[bk.size()-1];
		cout<<rt;
		int lc=md.find(rt);
		dfs(md.substr(0,lc),bk.substr(0,lc));
		dfs(md.substr(lc+1),bk.substr(lc,bk.size()-lc-1));
	}
	//找到根并输出 
	
	//fn+=rt;
	
	//只有一个结点时退出循环 
	//if(bks==1) return;
	//分解后递归
	//中序 ,find() 
	//从0截取i的长度--左 
//	string mdleft=md.substr(0,lc);
//	//从i+1到结尾 
//	string mdright=md.substr(lc+1);
//	//左右中--左
//	string bkleft=bk.substr(0,lc);
//	//右,截取到结尾并减去根节点,lc这里出错 
//	string bkright=bk.substr(lc,bks-lc-1);
	
	//递归
	 
}
int main(){
	cin>>md;
	cin>>bk;
	dfs(md,bk);
	cout<<endl;
	
	return 0;
} 
