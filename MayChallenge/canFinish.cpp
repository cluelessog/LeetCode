class Solution {
    bool hasCycle(vector<int>& visited,vector<int> adj[],int source)
    {
        if(visited[source] == 1) return true;
        if(visited[source] == 0)
        {
            visited[source] = 1; //not all neighbours are processed 1->Grey
            for(auto v : adj[source])
            {
                if(hasCycle(visited,adj,v)) return true;
            }
        }
        visited[source] = -1; //fully visited node -1->Black
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*using stack
        if(numCourses && prerequisites.size() == 0) return true;
        int inDegree[numCourses];
        memset(inDegree,0,sizeof(inDegree));
        for(int i = 0 ; i < prerequisites.size(); i++)
        {
            inDegree[prerequisites[i][0]]++;
        }
        
        stack<int> s;
        for(int i = 0 ; i < numCourses; i++)
        {   //cout << "inDegree[i] "<<inDegree[i] <<endl;
            if(inDegree[i] == 0)
            {
                s.push(i);
            }
        }
        int count = 0;
        while(!s.empty())
        {
            int top = s.top();
            s.pop();
            count++;
            for(int i = 0 ; i < prerequisites.size(); i++)
            {
                if(prerequisites[i][1] == top)
                { 
                    inDegree[prerequisites[i][0]]--;
                    if(inDegree[prerequisites[i][0]] == 0)
                    {
                        s.push(prerequisites[i][0]);
                    }
                }
            }
        }
        return count == numCourses;*/
        //recursive approach
        vector<int> adj[numCourses];
        for(auto i : prerequisites)
        {
            adj[i[0]].push_back(i[1]);
        }
        vector<int> visited(numCourses+1,0);//all nodes are not visited yet 0->white
        for(int i = 0 ; i < numCourses; i++)
        {
            if(hasCycle(visited,adj,i)) return false;
        }
        return true;
    }
};
