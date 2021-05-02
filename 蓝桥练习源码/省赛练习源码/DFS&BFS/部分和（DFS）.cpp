#include<bits/stdc++.h>
using namespace std;
//递归调用时不要在函数传递的地方用表达式（++i） 
int n,k;
//传递的有a-原始数组，k-剩余的量，cur-遍历的层次(第几个数)，ints-形成的集合 
void dfs(int a[],int len,int k,int cur,vector<int> ints){
	//边界条件
	if(k==0){
		int kk=0;
		for(int i=0;i<ints.size();++i){
			cout<<ints[i]<<"+";
			kk+=ints[i]; 
		}
		cout<<"yes("<<kk<<"=";
		cout<<")"<<endl;
		exit(0);
	} 
	if(cur==len || k<0) return;
	
	//不用第cur层的值
	cur++; 
	bfs(a,len,k,cur,ints);
	//用第cur层的值
	ints.push_back(a[cur]);
	k-=a[cur]; 
	bfs(a,len,k,cur,ints);
	ints.pop_back();//回溯 
}
int main(){
	cin>>n;
	int a[n];
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	cin>>k;
	vector<int> ints;
	int cur=0;
	bfs(a,n,k,cur,ints);
	
	return 0;
} 
