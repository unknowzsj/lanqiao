#include<iostream>
#include<algorithm>
using namespace std;
/*
	4n皇后问题 
*/
int n;
//个数 
int cot;
/*
bool check(int rec[],int x,int y){
	//rec[i]代表的是i行的列数 
	int k=sizeof(rec)/sizeof(rec[0]);
	for(int i=0;i<k;++i){
		//不考虑行，因为每次遍历必是空行 
		if(rec[i]==y) return false;
		//正对角线 
		if(i+rec[i]==x+y) return false;
		//副对角线
		if(rec[i]-i==y-x) return false;
		return true; 
	}
} 
*/
void dfs(int rec[],int row,int n){
	//遍历到超出最后一行代表完成一种情况 
	if(row==n){
		cot++;
		return;
	}
	for(int col=0;col<n;++col){
		//检测row和col位置是否合法，进行下一步 
		bool ok=true;
		//检查之前的行的列是否等于现在的col 
		for(int i=0;i<row;++i){
			//i+rec[i]==row+col||rec[i]-i==col-row是对角线的规则 
			if(rec[i]==col||i+rec[i]==row+col||rec[i]-i==col-row){
				ok=false;
				break;
			} 
		}
		if(ok){
			//记录第row行选择col列 
			rec[row]=col;
			//进行下一行 
			dfs(rec,row+1,n);
			rec[row]=0;//进行回溯 
		}
	} 
}
int main(){
	cin>>n;
	int res[n];
	int row=0;
	dfs(res,row,n);
	cout<<cot<<endl;
	
	return 0;
}
