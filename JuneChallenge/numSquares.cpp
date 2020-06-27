class Solution {
public:
    int numSquares(int n) {
        if(n < 4) return n;
        //similar to coin change problem
        int dp[n+1];
        memset(dp,1000000,sizeof(dp));
        //cout << dp[7];
        dp[0] = 0; dp[1] = 1; dp[2] = 2 ; dp[3] = 3;
        
        for(int sum = 4; sum <= n; sum++) //for each sum value we need
        {
            for(int sqr = 1; sqr*sqr <= sum ; sqr++)// check squares upto that sum whether to include or exclude
            {
                dp[sum] = min(dp[sum],dp[sum-(sqr*sqr)]+1);
            }
        }
        return dp[n];
    }
};
