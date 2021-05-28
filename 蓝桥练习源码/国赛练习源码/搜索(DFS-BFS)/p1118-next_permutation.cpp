#include<bits/stdc++.h>
using namespace std;//关键是检查的代码会超时 
int n,sum;//利用杨辉三角进行解答 
int yh[15][15]; 

int main(){
	cin>>n>>sum;
	int num[n]={0};
	for(int i=0;i<n;++i){
		num[i]=i+1;
	}
	//杨辉三角 
	yh[1][1]=1;
	for(int i=2;i<=n;++i){
		for(int j=1;j<=i;++j){
			yh[i][j]=yh[i-1][j]+yh[i-1][j-1];
		}
	}
	//next_permutation
	sort(num,num+n);//排序，从小到大，则字典序也是正确的 
	do{
		int all=0;
		int flag=0; 
		for(int i=1;i<=n;++i){
			all+=yh[n][i]*num[i-1];
			if(all>sum){//关键处,当和超过sum直接退出该排列 
				sort(num+i,num+n,greater<int>());//排序后，跳过一些更大的排列 
				flag=1;
				break; 
			}
		}
		if(flag==1) continue;
		//输出 
		if(all==sum){
			for(int i=0;i<n;++i){
				cout<<num[i]<<" "; 
			}
			cout<<endl;
			exit(0);
		} 
	}while(next_permutation(num,num+n));
	
	return 0;
} 
