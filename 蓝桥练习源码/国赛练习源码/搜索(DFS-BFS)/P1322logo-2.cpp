#include<bits/stdc++.h>
using namespace std;
string str;//遇到空格会结束读取 

int fuc(){
	char sta,nth;
	string wde;
	int k,all=0;
	//开始遍历
	while(cin>>sta){
		if(sta==']') break;//遇到]表示结束输入
		cin>>wde>>k;//读入结尾的字符和走的步数（循环次数）
		//repeat,重复 
		if(sta=='R'){
			nth=getchar();//读入[ 
			all+=k*fuc();//开始内部的循环
			nth=getchar();//读]后的‘’ 
		} 
		//bk,后退 
		if(sta=='B'){
			nth=getchar();//读K 
			all-=k; 
		}
		//fd,前进 
		if(sta=='F'){
			nth=getchar();//读D 
			all+=k; 
		}
		if(nth==']') break;//结束不是]，则一直读取输入，前后两个用于判断，防止遗漏 
	}
	return all;//返回计算的步数 
} 
int main(){
	cout<<abs(fuc());//abs()取绝对值 
	
	return 0;
}
