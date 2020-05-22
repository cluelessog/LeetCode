class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ana;
        if(p.size() > s.size())
        {
            return ana;
        }
        vector<int> scount(26,0);
        vector<int> pcount(26,0);
        for(int i = 0; i < p.size(); i++)
        {
            scount[s[i]-'a']++;
            pcount[p[i]-'a']++;
        }
        if(scount == pcount)
        {
            ana.push_back(0);
        }
        int i = p.size();
        while(i < s.size())
        {
            scount[s[i-p.size()]-'a']--;
            scount[s[i]-'a']++;
            if(scount == pcount)
            {
                ana.push_back(i-p.size()+1);
            }
            i++;
        }
        return ana;
    }
};
