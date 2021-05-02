#include<bits/stdc++.h>
using namespace std;
int N,X,Y;
int main(){
	cin>>N;
	int loc[N+1][4]={0};
	//读取信息 
	for(int i=1;i<=N;++i){
		cin>>loc[i][0];//x
		cin>>loc[i][1];//y
		cin>>loc[i][2];//x
		cin>>loc[i][3];//y
	}
	cin>>X>>Y;
	//暴力
	int mx=-1;//无结果输出-1 
	for(int i=1;i<=N;++i){
		//如果再范围内，则最大值为i 
		if(X>=loc[i][0]&&X<=loc[i][0]+loc[i][2]&&Y>=loc[i][1]&&Y<=loc[i][1]+loc[i][3]) mx=i;
	}
	cout<<mx<<endl;
	
	return 0; 
} 
