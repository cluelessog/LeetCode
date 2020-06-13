class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return nums;
        sort(nums.begin(),nums.end());
        int dp[nums.size()];
        memset(dp,1,sizeof(dp));
        int maxEle = INT_MIN;
        vector<int> result;
        for(int i = 1;  i < nums.size(); i++)
        {
            for(int j = i-1 ; j >=0 ; j--)
            {
                if(nums[i]%nums[j] == 0)
                {
                    if(dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        
                    }
                }
            }
        
            if(maxEle < dp[i])
            {
                maxEle = dp[i];
            }
        }
        
        for(int i = nums.size()-1; i >=0 ; i--)
        {
            if(dp[i] == maxEle)
            {
                result.push_back(nums[i]);
                maxEle--;
            }
        }
        
        return result;
    }
};
