class Solution {
public:
    int numTrees(int n) {
        
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        dp[1] = 1;
        //t(n) = sum(1 to n)[t(i-1)t(n-i)]
        for(int i = 2; i < n+1; i++)
        {
            for(int j = 0; j < i; j++)
            {
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};
