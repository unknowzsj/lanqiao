#include<bits/stdc++.h>
using namespace std;
int dp1[100010];
int dp2[100010];
int num[100010];
int cot;
//O(n^2) 
int main(){
	int n=0;//读取数据，先enter，再ctrl+z + enter结束 
	while(cin>>num[++n]);
	n--;//这里的n会多一个 
	 
	//找到最多的导弹数 
	int mlen=0;
	for(int i=1;i<=n;++i){
		dp1[i]=1;
		dp2[i]=1;//初始化
		for(int j=1;j<i;++j){
			if(num[j]>=num[i]){//最长不升序，可以等于 
				dp1[i]=max(dp1[i],dp1[j]+1);//只要满足条件，便表示num[i]可以作为末尾 
			}else if(num[j]<num[i]){//最长上升序列 
				dp2[i]=max(dp2[i],dp2[j]+1);
			}
		}
		mlen=max(mlen,dp1[i]);
		cot=max(cot,dp2[i]); 
	}
	cout<<mlen<<endl<<cot;
	
	return 0;
}
