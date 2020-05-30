class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ret;
        int n = points.size();
        vector<pair<float,int>> storeDistance;
        for(int i = 0 ; i < n; i++)
        {
            float distance = sqrt((points[i][0]*points[i][0]) + (points[i][1]*points[i][1]));
            storeDistance.push_back(make_pair(distance,i));
        }
        sort(storeDistance.begin(),storeDistance.end());
        for(int i = 0 ; i < K; i++)
        {
            vector<int> v;
            v.push_back(points[storeDistance[i].second][0]);
            v.push_back(points[storeDistance[i].second][1]);
            ret.push_back(v);
        }
        return ret;
    }
};
