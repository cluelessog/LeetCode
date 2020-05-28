class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> count(num+1,0);
        for(int i = 1; i <= num; i++)
        {
            // if(i%2 == 0)
            // {
            //     count[i] = count[i/2];
            // }
            // else
            // {
            //     count[i] = 1 + count[i/2];
            // }
            count[i] = count[i/2] + i%2;
        }
        return count;
    }
};
