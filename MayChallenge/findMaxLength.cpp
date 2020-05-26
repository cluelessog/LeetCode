class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> umap; //stores count,index
        int count = 0;
        int maxi = 0;
        for(int i  = 0 ; i < nums.size(); i++)
        {
            count = count + ((nums[i] == 0)?-1:1);
            if(count == 0) maxi = i+1;
            else if(umap.find(count) != umap.end()) maxi = max(maxi,i - umap.at(count));
            else umap[count] = i;
        }
        return maxi;
        
    }
};
