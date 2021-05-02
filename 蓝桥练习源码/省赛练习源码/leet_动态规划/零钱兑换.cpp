class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=size(coins);
        int dp[amount+1];
        int Max=amount+1;
        memset(dp,Max,amount+1);
        dp[0]=0;

        for(int i=1;i<amount+1;++i){
            for(int j=0;j<n;++j){
                if(i>coins[j]){
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        return dp[amount]>amount ? -1:dp[amount];
    }
};
