class Solution {
    int getcost(priority_queue<pair<int,int>>& pq, int size, int k,vector<vector<int>>& costs)
    {
        int minCost = 0;
        int i = 0;
        while(!pq.empty() and i < size/2)
        {
            int cost = costs[pq.top().second][k];
            minCost += cost;
            pq.pop();
            i++;
        }
        return minCost;
    }
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int size = costs.size();
        priority_queue<pair<int,int>> pq;
        for(int i = 0 ; i < size; i++)
        { 
            pq.push(make_pair(costs[i][0]-costs[i][1],i));
        }
        return getcost(pq,size,1,costs) + getcost(pq,size,0,costs);
    }
};
