#include<bits/stdc++.h>
using namespace std;//拿了70分 
string wrd="#";
int dp[1010][1010];

int main(){
	string str;
	cin>>str;
	wrd+=str;
	fill(dp[0],dp[0]+1010*1010,10000);//
	dp[1][1]=0;//取头一个数不需要补 
	//从第二个位置开始 
	for(int i=2;i<wrd.size();++i){//以i结尾 
		dp[i][i]=0;//单个字符不需要补 
		for(int j=i-1;j>=1;--j){
			if(str[j]==str[i]){
				if(i-j==1) dp[j][i]=0;
				else dp[j][i]=dp[j+1][i-1];//等于中间的 
			}else{
				if(i-j==1) dp[j][i]=1;//两个数不相等，补一个就可以
				else dp[j][i]=min(dp[j][i-1],dp[j+1][i])+1;
			} 
		}
	}
	cout<<dp[1][wrd.size()-1];
	
	return 0;
} 
