class Solution {
public:
    vector<int> prefixSum;
    Solution(vector<int>& w) {
        prefixSum.push_back(w[0]);
        for(int i = 1 ; i < w.size(); i++)
        {
            prefixSum.push_back(w[i] + prefixSum[i-1]);
        }
        
    }
    
    int pickIndex() {
        int val = rand()%prefixSum.back();
        auto it = upper_bound(prefixSum.begin(), prefixSum.end(),val);
        return it - prefixSum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
