#include<bits/stdc++.h>
using namespace std;
int n,cts;
int dj[2][50];//对角线选择加n，这里至少是2*n 
int lie[15];
int res[15];//记录路径 

void dfs(int h){
	if(h==n+1){//到最后一行完成，打印并退出 
		if(cts<3){
			for(int i=1;i<=n;++i) cout<<res[i]<<" ";
			cout<<endl;
		}
		cts++; 
		return;
	}
	//遍历列 
	for(int i=1;i<=n;++i){
		if(lie[i]==0&&dj[0][i+h]==0&&dj[1][(i-h+n)]==0){
			lie[i]=1;
			dj[0][i+h]=1;//从对角线  
			dj[1][i-h+n]=1;//+n是为了防止产生负数，主对角线 
			res[h]=i;//第h行，第i列 
			
			dfs(h+1);
			//回溯
			lie[i]=0;
			dj[0][i+h]=0; 
			dj[1][i-h+n]=0;
		} 
	}
}

int main(){
	cin>>n;
	
	//开始遍历
	dfs(1);//第1行开始 
	cout<<cts;
	
	return 0;
}
