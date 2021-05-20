#include<bits/stdc++.h>
using namespace std;
int dp1[100010];
int dp2[100010];
int num[100010];
//O(nlogn) 
int main(){
	int n=0;//读取数据，先enter，再ctrl+z + enter结束 
	while(cin>>num[++n]);
	n--;//这里的n会多一个 
	 
	//找到最多的导弹数 
	int len1=1,len2=1;
	dp1[1]=dp2[1]=num[1];//初始化 
	for(int i=2;i<=n;++i){
		//最长不上升序列
		if(dp1[len1]>=num[i]) dp1[++len1]=num[i];//如果num[i]符合条件，将其加入队列中
		else *upper_bound(dp1+1,dp1+1+len1,num[i],greater<int>())=num[i];//已有序列中找到比num[i]小的第一个元素进行替换 
		
		//最长上升子序列 --当dp2[len2]=num[i]时，自己替换自己，不影响 
		if(dp2[len2]<num[i]) dp2[++len2]=num[i];//如果num[i]符合条件，将其加入队列中
		else *lower_bound(dp2+1,dp2+1+len2,num[i])=num[i];//已有序列中找到比num[i]大（等于）的第一个元素进行替换 
	}
	cout<<len1<<endl<<len2;
	
	return 0;z 
}
