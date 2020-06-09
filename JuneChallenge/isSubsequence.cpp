class Solution {
public:
    bool isSubsequence(string s, string t) {
        /*
        dynamic programming solution
        int slen = s.size();
        int tlen = t.size();
        int dp[slen+1][tlen+1];
        memset(dp,-1,sizeof(dp));
        for(int i = 0; i <= slen; i++)
        {
            for(int j = 0 ; j <= tlen; j++)
            {
                if(i*j == 0) dp[i][j] = 0;
                else if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[slen][tlen] == slen;
        */
        int count = 0;
        for(int i = 0 ; i < t.size(); i++)
        {
            if(count < s.size() && t[i] == s[count])
            {
                count++;
            }
        }
        return count == s.size();
     }
};
