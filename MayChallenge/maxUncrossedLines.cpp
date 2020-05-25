// class Solution {
   
//     int helper(int i , int j, vector<int>& A, vector<int>& B,int dp[501][501])
//     {
//         if(i == A.size() || j == B.size()) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
//         if(A[i] == B[j]) dp[i][j] = 1 + helper(i+1,j+1,A,B,dp);
//         else
//         {
//             dp[i][j] = max(helper(i+1,j,A,B,dp),helper(i,j+1,A,B,dp));
//         }
//         return dp[i][j];
//     }
// public:
//     int maxUncrossedLines(vector<int>& A, vector<int>& B) {
//         int dp[501][501];
//         memset(dp,-1,sizeof(dp));
//         return helper(0,0,A,B,dp);
//     }
// };
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int M = A.size(), N = B.size();
        int dp[M+1][N+1];
        memset(dp,0,sizeof(dp));
        for(int i = 0 ; i < M; i++)
        {
            for(int j = 0 ; j < N; j++)
            {
                if(A[i] == B[j]) dp[i+1][j+1] = 1 + dp[i][j];
                else dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
                
         
        return dp[M][N];
    }
};
