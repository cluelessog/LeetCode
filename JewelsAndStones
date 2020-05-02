class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count = 0;
        set<int> jewel;
        for(int i = 0; i < J.size(); i++)
        {
            jewel.insert(J[i]);
        }
        for(int i = 0 ; i < S.size(); i++)
        {
            if(jewel.find(S[i]) != jewel.end())
            {
                count++;
            }
        }
        return count;
    }
};
