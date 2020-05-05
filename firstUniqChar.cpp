class Solution {
public:
    int firstUniqChar(string s) {
        // int charArray[26] = {0};
        // int index = -1;
        // for(int i = 0 ; i < s.size(); i++)
        // {
        //     charArray[s[i]-'a']++;
        // }
        // for(int i = 0; i < s.size(); i++)
        // {
        //     if(charArray[s[i]-'a'] == 1)
        //     {
        //         index = i;
        //         break;
        //     }
        // }
        pair<int,int> freqPair[26];
        for(int i = 0; i < s.size(); i++)
        {
            freqPair[s[i]-'a'].first++;
            freqPair[s[i]-'a'].second = i;
        }
        int res = INT_MAX;
        for(int i = 0; i < 26; i++)
        {
            if(freqPair[i].first == 1)
            {
                res = min(res,freqPair[i].second);
            }
        }
        if(res == INT_MAX)
        {
            return -1;
        }
        return res;
    }
};
