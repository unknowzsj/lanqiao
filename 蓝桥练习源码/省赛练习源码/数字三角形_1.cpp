#include<bits/stdc++.h>
using namespace std;

int N;
 
int main(){
	cin>>N;
	int map[N+1][N+1];
	int value[N+1][N+1];
	//初始化
	memset(map,0,sizeof(map)); 
	memset(value,0,sizeof(value));
	for(int i=1;i<N+1;++i){
		for(int j=1;j<=i;++j){
			cin>>map[i][j];
			value[i][j]=map[i][j]+max(value[i-1][j-1],value[i-1][j]);
		}
	}
	//通过奇偶来满足左下右下相差不为1 
	if(N%2==0) cout<<max(value[N][N/2],value[N][N/2+1])<<endl;
	else cout<<value[N][(N+1)/2]<<endl;
} 
