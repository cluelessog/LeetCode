class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
         ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];
        int x2 = coordinates[1][0];
        int y2 = coordinates[1][1];
        if(coordinates.size() == 2)
        {
            return true;
        }
        int m;
        if((x2-x1) != 0)
        {
            m = (y2-y1)/(x2-x1);
        }
        for(int i = 2; i < coordinates.size(); i++)
        {
                if(coordinates[i][1] != (m*(coordinates[i][0]-x1) + y1 ))
                {
                    return false;
                }  
        }
        
        return true;
    }
};
