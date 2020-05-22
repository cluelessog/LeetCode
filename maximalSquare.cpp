class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0)return 0;
        int r = matrix.size();
        int c = matrix[0].size();
        int preprocess[r][c];
        memset(preprocess,0,sizeof(preprocess));
        int max = 0;
        int area = 0;
        for(int i = 0 ; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(matrix[i][j] == '1')
                {
                    if(i*j == 0) preprocess[i][j] = 1;
                    else
                    {
                    preprocess[i][j] = 1 + min(preprocess[i-1][j-1],min(preprocess[i][j-1],preprocess[i-1][j]));
                    }
                }
                if(preprocess[i][j] >= max)
                {
                    max = preprocess[i][j];
                    area = max*max;
                    
                }
            }
        }
        
        return area;
    }
};
