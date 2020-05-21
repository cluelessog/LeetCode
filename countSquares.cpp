class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int preprocess[r][c];
        memset(preprocess,0,sizeof(preprocess));
        int ans = 0;
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c ; j++)
            {
                if(matrix[i][j] == 1)
                {
                    if(i*j == 0) preprocess[i][j] = 1;
                    else
                    {
                    preprocess[i][j] = 1 + min(min(preprocess[i][j-1],preprocess[i-1][j]),preprocess[i-1][j-1]);
                    }
                    
                }
                ans += preprocess[i][j];
            }
        }
        return ans;
    }
};
