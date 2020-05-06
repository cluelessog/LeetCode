//hashmap solution
// class Solution {
// public:
//     Solution() {ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);}
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int, int> umap;
//         for(int i = 0 ; i < nums.size(); i++)
//         {
//                 umap[nums[i]]++;
          
//         }
//         int freq = -1;
//         int majority = -1;
//         for(auto &i : umap)
//         {
//             //cout << i.first << " " << i.second << endl;
//             if(i.second > freq)
//             {
//                 majority = i.first;
//                 freq = i.second;
//             }
//         }
//      return majority;
//    }
// };

class Solution {
public:
    Solution() {ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);}
    int majorityElement(vector<int>& nums) {   
        int count = 0,ans = 0;
        for(auto &i : nums)
        {
            if(count == 0)
                ans = i;
            count += (ans == i) ? 1 : -1;
        }
        return ans;
    }
};
