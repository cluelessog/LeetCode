// class Solution {
//     bool dfs(vector<int> adj[], vector<int>& color,int node, int col)
//     {
//         if(color[node] != 0)//already colored
//         {
//             return color[node] == col; //if not the color we want, return false
//         }
//         color[node] = col; //color this node
//         for(auto i : adj[node]) //color all neighbours with different color
//         {
//             if(!dfs(adj,color,i,-col)) return false;
//         }
//         return true;
//     }
// public:
//     bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
//         //creating adjacency list graph representation
//         vector<int> adj[N+1]; //N->V
//         for(auto i : dislikes)
//         {
//             adj[i[0]].push_back(i[1]);
//             adj[i[1]].push_back(i[0]);
//         }
//         vector<int> color(N+1,0);
//         for(int i = 1; i <= N; i++)
//         {
//             if(color[i] == 0 && !dfs(adj,color,i,1)) return false;
//         }
//         return true;
//     }
// };
class Solution {
    bool dfs(vector<int> adj[], vector<int>& color,int s, int col)
    {
        color[s] = col;
        for(auto v : adj[s])
        {
            if(color[s] == color[v]) return false;
            else if(color[v] == 0)
            {
                dfs(adj,color,v,-col);
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        //creating adjacency list graph representation
        vector<int> adj[N+1];
        for(auto i : dislikes)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> color(N+1,0);
        for(int s = 1; s <= N; s++)
        {
            if(color[s] == 0 && !dfs(adj,color,s,1))
            {
                return false;
            }
        }
        return true;
    }
};
