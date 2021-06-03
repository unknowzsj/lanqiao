#include<bits/stdc++.h>
using namespace std;
int n;
string res="";

void dfs(int cur){
	if(cur==4){//4之后特殊处理 
		cout<<res<<endl;
		char c=res[cur-1];
		char d=res[cur];
		res[cur-1]=res[cur]='-';
		res[2*cur]=c;
		res[2*cur+1]=d;
		cout<<res<<endl;
		//特殊处理
		//第一步 
		res[3]=res[7];
		res[4]=res[8];
		res[7]=res[8]='-';
		cout<<res<<endl;
		//第二步 
		res[1]=res[2]='-';
		res[7]=res[8]='o';
		cout<<res<<endl;
		//第三步 
		res[1]=res[6]; 
		res[2]=res[7];
		res[6]=res[7]='-';
		cout<<res<<endl;
		//第四步
		res[6]=res[0]; 
		res[7]=res[1];
		res[0]=res[1]='-';
		cout<<res<<endl;
		
		return;
	}
	cout<<res<<endl;
	//进行替换 
	char a=res[cur-1];
	char b=res[cur];
	res[cur-1]=res[cur]='-';
	res[2*cur]=a;
	res[2*cur+1]=b;
	cout<<res<<endl;
	//将空格换到后面
	res[cur-1]=res[cur]='*';
	res[2*(cur-1)]=res[2*(cur-1)+1]='-';
	//遍历
	dfs(cur-1); 
}
int main(){
	cin>>n;
	string wht="";
	string blk="";
	for(int i=0;i<n;++i){
		wht+='o';
		blk+='*';
	}
	res=wht+blk+"--";
	dfs(n);
	
	return 0;
}
