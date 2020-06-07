class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount+1];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        
        for(int j = 0; j < coins.size(); j++)
        {   
            for(int am = 1 ; am <= amount; am++)
            {
                if(am >= coins[j])
                {
                    dp[am] += dp[am-coins[j]];
                }
                 
            }
        }
        
        return dp[amount];
    }
};
