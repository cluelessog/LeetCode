class Solution {
    
    static bool compare(vector<int>& a, vector<int>& b)
    {
        return (a[0] > b[0]) || (a[0] == b[0] && a[1] < b[1]);
    }
    //revisit this question
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        sort(people.begin(),people.end(),compare);
        vector<vector<int>> result;
        for(int i = 0 ; i < people.size(); i++)
        {
                result.insert(result.begin()+people[i][1],people[i]);
        }
        return result;
    }
};
