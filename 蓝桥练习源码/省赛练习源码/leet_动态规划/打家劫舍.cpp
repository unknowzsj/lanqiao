#include<bits/stdc++.h>
using namespace std;

int n;
int main(){
	cin>>n;
	int dp[n+3];
	int val[n];
	for(int i=0;i<n;++i) cin>>val[i];
	//初始化
//	dp[0]=val[0];
//	dp[1]=val[1];
//	dp[2]=val[0]+val[2];
	memset(dp,0,n+3);
	
	//转移方程 
	for(int i=3;i<n+3;++i){
		dp[i]=max(dp[i-2],dp[i-3])+val[i-3];
	}
	int max=INT_MIN;
	for(int i=0;i<n+3;++i) {
		if(max<dp[i]) max=dp[i];
	}
	cout<<max<<endl;
	
	return 0;
}

/*
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=size(nums);
        int dp[n];
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);

        for(int i=2;i<n;++i){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        int max=INT_MIN;
        for(int i=0;i<n;++i) {
            if(max<dp[i]) max=dp[i];
        }
        return max;
    }
};
