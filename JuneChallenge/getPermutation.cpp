class Solution {
public:
    string getPermutation(int n, int k) {
        
        if(n==0) return " ";
        vector<int> fact;
        vector<int> set;
        int factval = 1;
        string ans = "";
        for(int i = 0 ; i <= n; i++)
        {     
            if(i != 0)
            {
                factval *= i;     
                set.push_back(i);
            }
            fact.push_back(factval);
        }
        for(int i = n; i > 0; i--)
        {
             int val = (k-1)/fact[i-1];
             ans += to_string(set[val]);
             k -= val*fact[i-1];
             set.erase(set.begin() + val);
        }
        return ans;
    }
};
