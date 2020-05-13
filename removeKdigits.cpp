class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() == k)
        {
            return to_string(0);
        }
        for(int i = 1 ; i <= k; i++)
        {
            int j = 0;
            while(j < num.size()-1 && num[j] <= num[j+1])
            {
             j++;   
            }
            num.erase(j,1);
            while(num.size() > 1 && num[0] == '0')
            {
                num.erase(0,1);
            }
            
        }
        return num;
    }
};
