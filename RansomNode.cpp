class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int maxCount[26] = {0};
        for(int i = 0; i < magazine.size(); i++)
        {
            maxCount[magazine[i]-97]++;
        }
        for(int i = 0; i < ransomNote.size(); i++)
        {
            maxCount[ransomNote[i]-97]--;
            if(maxCount[ransomNote[i]-97] < 0)
            {
                return false;
            }
        }
        return true;
    }
};
