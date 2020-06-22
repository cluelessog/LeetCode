class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        //bit sum method
        long ans = 0;
        int pos  = 0;
        int sum;
        int bit;
        for(int i = 0 ; i < 32; i++)
        {
            sum = 0;
            for(int j = 0; j < nums.size(); j++)
            {
                bit = nums[j]&1;
                sum += bit;
                nums[j] = nums[j]>>1;
            }
            sum = sum%3;
            ans = ans + sum*pow(2,pos);
            pos++;
        }
        return ans;
    }
};
