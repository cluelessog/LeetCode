class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> Ans;
        int i = 0;
        int j = 0;
        while(i < A.size() && j < B.size())
        {
            int l = max(A[i][0],B[j][0]);
            int h = min(A[i][1],B[j][1]);
            //cout << "l " << l << " h " << h << endl;
            if(l <= h) //overlap case
            {
                vector<int> v = {l,h};
                Ans.push_back(v);
            }
            if(A[i][1] < B[j][1]) //smallest endpoint removed
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return Ans;
    }
};
