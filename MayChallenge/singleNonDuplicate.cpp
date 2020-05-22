class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // int val = 0;
        // for(auto i : nums)
        // {
        //     val ^= i;
        // }
        // return val;
        int l = 0;
        int r = nums.size()-1;
        if(r == 0)
        {
            return nums[0];
        }
        if(nums[0] != nums[1])
        {
            return nums[0];
        }
        int val = -1;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid-1] != nums[mid] && nums[mid+1] != nums[mid])
            {
                val = nums[mid];
                break;
            }
            
            if((mid%2 == 0 and nums[mid] == nums[mid+1]) or (mid%2 == 1 and nums[mid] == nums[mid-1]))
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
              
        }
        return val;
    }
};
