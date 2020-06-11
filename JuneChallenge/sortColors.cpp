class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;
        //range
        //low............mid...........high............n-1
        //   111111111111     unknowns      2222222222
        
        while(mid<=high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[high],nums[mid]);
                high--;
            }
        }
    }
};
