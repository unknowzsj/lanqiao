#include<bits/stdc++.h>
using namespace std;
string wrd="#",str="#";
int dp[1010][1010];

int main(){
	string s;
	cin>>s;
	wrd+=s;
	reverse(s.begin(),s.end());//·´×ª×Ö·û´®
	str+=s;
	int len=s.size();
	for(int i=1;i<=len;++i){
		for(int j=1;j<=len;++j){
			if(str[i]==wrd[j]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	} 
	cout<<len-dp[len][len];
	
	return 0; 
} 
